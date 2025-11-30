#pragma once
#include <iostream>

using std::string;
using std::to_string;


typedef enum{
    mode_read,
    mode_write
} pin_mode_t;



class mypin
{
private:
    pin_mode_t mode;
    int fd;
    int pin_num;
public:
    mypin(int num, pin_mode_t _mode);
    void operator<<(int val);
    void operator>>(int& val);
    ~mypin();
};

