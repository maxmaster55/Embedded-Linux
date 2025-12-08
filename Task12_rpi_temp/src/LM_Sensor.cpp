#include <LM_sensor.h>

LM_Sensor::LM_Sensor(int pin)
{
    // Use I2C instead of serial
    char filename[20];
    snprintf(filename, sizeof(filename), "/dev/i2c-%d", 1);  // I2C bus 1
    
    serial_fd = open(filename, O_RDWR);
    if (serial_fd < 0) {
        std::cerr << "Error opening I2C bus: " << strerror(errno) << std::endl;
        return;
    }
    
    // Set I2C slave address (default 0x08, common for Arduino/ESP)
    const int I2C_ADDRESS = 0x48;
    if (ioctl(serial_fd, I2C_SLAVE, I2C_ADDRESS) < 0) {
        std::cerr << "Error setting I2C address 0x" << std::hex << I2C_ADDRESS 
                  << ": " << strerror(errno) << std::dec << std::endl;
        close(serial_fd);
        serial_fd = -1;
        return;
    }
    
    // Test connection by reading a byte
    uint8_t test_byte = 0;
    if (read(serial_fd, &test_byte, 1) < 0) {
        std::cerr << "Warning: Could not read from I2C device (device might not be ready)" << std::endl;
    }
    
    last_value = 0;
    
    std::cout << "I2C sensor initialized at address 0x" 
              << std::hex << I2C_ADDRESS << std::dec << std::endl;
}

int LM_Sensor::read_sensor()
{
    if (serial_fd < 0) {
        std::cerr << "I2C not initialized" << std::endl;
        return last_value;
    }

    uint8_t buffer[2] = {0};
    
    // Request 2 bytes from I2C device
    int bytes_read = read(serial_fd, buffer, 2);
    
    if (bytes_read != 2) {
        std::cerr << "I2C read failed: expected 2 bytes, got " << bytes_read 
                  << " (" << strerror(errno) << ")" << std::endl;
        
        // Try to recover by closing and reopening I2C
        close(serial_fd);
        char filename[20];
        snprintf(filename, sizeof(filename), "/dev/i2c-%d", 1);
        serial_fd = open(filename, O_RDWR);
        
        if (serial_fd >= 0 && ioctl(serial_fd, I2C_SLAVE, 0x08) >= 0) {
            std::cout << "I2C connection recovered" << std::endl;
        } else {
            std::cerr << "Failed to recover I2C connection" << std::endl;
            serial_fd = -1;
        }
        
        return last_value;
    }
    
    // Combine the two bytes (MSB first)
    int adc_value = (buffer[0] << 8) | buffer[1];
    
    // Debug output
    std::cout << "Raw I2C data: [" << (int)buffer[0] << ", " << (int)buffer[1] 
              << "] -> ADC: " << adc_value << std::endl;
    
    last_value = adc_value;
    return adc_value;
}

// Alternative version if ESP sends data differently
int LM_Sensor::read_sensor_alternative()
{
    if (serial_fd < 0) {
        return last_value;
    }
    
    // Method 1: Simple read
    uint8_t buffer[2];
    if (read(serial_fd, buffer, 2) == 2) {
        int adc_value = (buffer[0] << 8) | buffer[1];
        last_value = adc_value;
        return adc_value;
    }
    
    // Method 2: Write-then-read (if ESP needs a trigger)
    uint8_t command = 0x01;  // "Send data" command
    if (write(serial_fd, &command, 1) == 1) {
        usleep(10000);  // Wait 10ms for response
        
        uint8_t buffer[2];
        if (read(serial_fd, buffer, 2) == 2) {
            int adc_value = (buffer[0] << 8) | buffer[1];
            last_value = adc_value;
            return adc_value;
        }
    }
    
    return last_value;
}

// Version that reads temperature directly (if ESP converts it)
float LM_Sensor::read_temperature()
{
    if (serial_fd < 0) {
        return last_value;
    }
    
    // Request temperature (4 bytes for float)
    uint8_t buffer[4];
    if (read(serial_fd, buffer, 4) == 4) {
        // Convert bytes to float
        float temp;
        memcpy(&temp, buffer, sizeof(float));
        last_value = static_cast<int>(temp);  // Store as int for backward compatibility
        return temp;
    }
    
    return static_cast<float>(last_value);
}

LM_Sensor::~LM_Sensor()
{
    if (serial_fd >= 0) {
        close(serial_fd);
    }
}