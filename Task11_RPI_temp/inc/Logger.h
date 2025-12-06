#include <iostream>
#include <memory>
#include "tempData.h"

using namespace std;

class Logger
{
private:
    
public:
    Logger(shared_ptr<TempDate> td_ptr);
    ~Logger();
};