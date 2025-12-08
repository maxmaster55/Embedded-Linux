#include <iostream>
#include <memory>
#include <LM_sensor.h>
#include <Logger.h>
#include <Display.h>
#include <tempData.h>




using namespace std;


int main(int argc, char const *argv[])
{
    
    shared_ptr<TempData> temp(new TempData);
    unique_ptr<LM_Sensor> sensor(new LM_Sensor(1));

    Logger logger;
    Display screen;

    while (true)
    {
        screen.displayTemp(temp);
        logger.logTemp(temp);
        
    }



    return 0;
}

