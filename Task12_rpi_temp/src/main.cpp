#include <iostream>
#include <memory>
#include <DHT_sensor.h>
#include <Logger.h>
#include <Display.h>
#include <tempData.h>




using namespace std;


int main(int argc, char const *argv[])
{
    
    unique_ptr<DHT_Sensor> sensor(new DHT_Sensor(1));
    shared_ptr<TempData> data(new TempData);

    Logger logger;
    Display screen;

    while (true)
    {
        data->set_temperature(sensor->read_temperature());
        data->set_humidity(sensor->read_humidity());

        screen.display_temperature(data);
        screen.display_humidity(data);

        logger.log_temperature(data);
        logger.log_humidity(data);
        
        sleep(1);
    }



    return 0;
}

