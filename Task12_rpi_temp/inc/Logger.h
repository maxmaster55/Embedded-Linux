#include <iostream>
#include <memory>
#include <fstream>
#include "tempData.h"
#include <ctime>



using namespace std;

class Logger
{
private:
        std::time_t now = std::time(nullptr);

public:
    void log_temperature(shared_ptr<TempData> td_ptr);
    void log_humidity(shared_ptr<TempData> td_ptr);
};