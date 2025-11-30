#include <iostream>
#include <thread>
#include <chrono>  
#include "mypin.h"


int main(int argc, char const *argv[])
{
    mypin pin(25, mode_write);
    for (int i = 0; i < 50; i++)
    {
        pin << 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        pin << 0;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    return 0;
}
