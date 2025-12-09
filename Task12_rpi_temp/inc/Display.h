#include <iostream>
#include <memory>
#include <ctime>
#include "tempData.h"

using namespace std;

class Display
{
private:
    std::time_t now = std::time(nullptr);

public:
    void display_temperature(shared_ptr<TempData> data);
    void display_humidity(shared_ptr<TempData> data);
};