#include <DHT_sensor.h>


DHT_Sensor::DHT_Sensor(int pin){
    temp_fd = open("/sys/bus/iio/devices/iio:device0/in_temp_input", O_RDONLY);
    if (temp_fd == -1)
    {
        perror("error with the temperature file");
    }
    hum_fd = open("/sys/bus/iio/devices/iio:device0/in_humidityrelative_input", O_RDONLY);
    if (hum_fd == -1)
    {
        perror("error with the humidity file");
    }
    
}
DHT_Sensor::~DHT_Sensor(){
    if (temp_fd != -1) close(temp_fd);
    
    if (hum_fd != -1) close(hum_fd);
    
}


int DHT_Sensor::read_temperature(){
    
    char buf[8] = {0};
    lseek(temp_fd, 0, SEEK_SET);
    read(temp_fd, buf, 8);

    int int_value = std::atoi(buf);
    return int_value;
}
int DHT_Sensor::read_humidity(){
    char buf[8] = {0};
    lseek(hum_fd, 0, SEEK_SET);
    read(hum_fd, buf, 8);
    
    int int_value = std::atoi(buf);
    return int_value;
}
