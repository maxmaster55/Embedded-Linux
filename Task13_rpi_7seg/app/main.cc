#include <iostream>
#include <thread>
#include <chrono>
#include "seven_seg.h"

using std::this_thread::sleep_for;
using std::chrono::seconds;

int main(int argc, char const *argv[])
{

    SevenSegment display({2, 3, 9, 17, 27, 22, 10}, false, std::cin, std::cout);
    

    int digit;
    display >> digit;
    display << digit;

    return 0;
}
