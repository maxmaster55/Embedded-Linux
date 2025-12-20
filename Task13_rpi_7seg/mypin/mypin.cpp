#include "mypin.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


mypin::mypin(int num, pin_mode_t _mode)
{
    pin_num = num + 512;
    mode = _mode;
    std::cout << num <<"=>" <<pin_num<< "\n";
    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0)
    {
        perror("error opening the file");
        throw std::runtime_error("system call failed");
    }
    
    string str_num = to_string(pin_num);
    write(fd, str_num.c_str(), str_num.size());
    close(fd);

    string dir_path = "/sys/class/gpio/gpio" + to_string(pin_num) + "/direction";
    fd = open(dir_path.c_str(), O_WRONLY);
    if (fd < 0) {
        perror("error opening direction");
        throw std::runtime_error("system call failed");
        return;
    }
    if (mode == mode_read)
    {
        write(fd, "in", 2);
    }else if (mode_write){
        write(fd, "out", 3);
    }
    close(fd);
    string value_path = "/sys/class/gpio/gpio" + to_string(pin_num) + "/value";
    if (mode == mode_read)
    { 
        fd = open(value_path.c_str(), O_RDONLY);
        std::cout<<"read mode\n";
    }else{
        fd = open(value_path.c_str(), O_WRONLY);
        std::cout<<"write mode\n";
    }

    if (fd < 0) {
        perror("error opening value");
        throw std::runtime_error("system call failed");
        return;
    }
}

mypin::mypin(mypin&& other) noexcept
{
    pin_num = other.pin_num;
    fd = other.fd;
    mode = other.mode;
    other.fd = -1;
}

mypin& mypin::operator=(mypin&& other) noexcept
{
    if (this != &other) {
        if (fd >= 0)
            close(fd);

        pin_num = other.pin_num;
        fd = other.fd;
        mode = other.mode;
        other.fd = -1;
    }
    return *this;
}


mypin::~mypin()
{
    if (fd < 0)
        return;
    std::cout<<"closing pin\n";
    close(fd);
    
    string unex = "/sys/class/gpio/unexport";
    fd = open(unex.c_str(), O_WRONLY);
    if (fd < 0) {
        perror("error opening unexport file");
        return;
    }
    string to_stop = to_string(pin_num);
    write(fd, to_stop.c_str(), to_stop.size());
    close(fd);
}

void mypin::operator<<(int val){
    if (mode != mode_write)
    {
        std::cout << "You can't write to a pin in read mode\n";
        throw std::runtime_error("system call failed");
        return;
    }
    string val_str = to_string(val);
    write(fd, val_str.c_str(), val_str.size());
}

void mypin::operator>>(int& val){
    if (mode != mode_read)
    {
        std::cout << "You can't read from a pin in write mode\n";
        throw std::runtime_error("system call failed");
        return;
    }

    char buff[2];
    lseek(fd, 0, SEEK_SET);      // rewind
    if (read(fd, buff, 2) < 0) {
        perror("error reading value");
        close(fd);
        throw std::runtime_error("system call failed");
        return;
    }

    val = buff[0] - '0';
}

