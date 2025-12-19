#include <iostream>
#include "seven_seg.h"



int main(int argc, char const *argv[])
{

    SevenSegment display({1, 2, 3, 4, 5, 6, 7}, std::cin, std::cout);

    int digit;
    display >> digit;
    display << digit;

    return 0;
}
