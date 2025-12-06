#include <iostream>
#include <memory>
#include "tempData.h"


using namespace std;

class Display
{
private:

public:
    void displayTemp(shared_ptr<TempData> data);
};