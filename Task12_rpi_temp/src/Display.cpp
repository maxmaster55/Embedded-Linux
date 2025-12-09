#include "Display.h"


void Display::display_temperature(shared_ptr<TempData> data){
    std::string ts = std::ctime(&now);
    ts.pop_back();
    cout<<"[" << ts <<"] the temperature is: " << data->read_temperature() << endl;
}

void Display::display_humidity(shared_ptr<TempData> data){
    std::string ts = std::ctime(&now);
    ts.pop_back();
    cout<<"[" << ts <<"] the humidity is: " << data->read_humidity() << endl;
}


