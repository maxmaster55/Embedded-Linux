#include <iostream>
#include <memory>
#include <LM_sensor.h>
#include <Logger.h>
#include <Display.h>
#include <tempData.h>




using namespace std;


int main(int argc, char const *argv[])
{
    
    unique_ptr<LM_Sensor> sensor(new LM_Sensor(1));
    shared_ptr<TempData> temp(new TempData);

    Logger logger;
    Display screen;

    while (true)
    {
        cout << "start \n";
        temp->setTemp(sensor->read_sensor());
        screen.displayTemp(temp);
        logger.logTemp(temp);
        sleep(1);
    }



    return 0;
}

