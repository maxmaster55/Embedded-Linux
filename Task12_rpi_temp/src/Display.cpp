#include "Display.h"


void Display::displayTemp(shared_ptr<TempData> data){
    
    cout<< "the temp is: " << data->read_temp() << endl;

}


