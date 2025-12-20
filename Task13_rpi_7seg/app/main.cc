#include <iostream>
#include <thread>
#include <chrono>
#include "seven_seg.h"

using std::this_thread::sleep_for;
using std::chrono::seconds;

int main(int argc, char const *argv[])
{

    SevenSegment display({2, 3, 9, 17, 27, 22, 10}, false, std::cin, std::cout);

    while (true)
    {
        std::string digit;
        display >> digit;
        int digit_int = std::atoi(digit.c_str());
        std::cout << "You entered: " << digit_int << "\n";
        display << digit_int;
    }

    return 0;
}
