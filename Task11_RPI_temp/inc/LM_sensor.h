#include <iostream>
#include <memory>

class LM_Sensor
{
private:
    int gpio_pin;
public:
    LM_Sensor(int pin);
    float readHumidity();
    ~LM_Sensor();
};
