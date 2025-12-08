#pragma once 

#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <cerrno>
#include <inttypes.h>

class LM_Sensor {
private:
    int serial_fd;  // Actually I2C file descriptor
    int last_value;
    
public:
    LM_Sensor(int pin);
    ~LM_Sensor();
    
    // Read raw ADC value from sensor
    int read_sensor();
    
    // Alternative reading method
    int read_sensor_alternative();
    
    // Read temperature directly (if supported)
    float read_temperature();
};

