#include <iostream>
#include <memory>
#include <fstream>
#include "tempData.h"




using namespace std;

class Logger
{
private:
    
public:
    void logTemp(shared_ptr<TempData> td_ptr);
};