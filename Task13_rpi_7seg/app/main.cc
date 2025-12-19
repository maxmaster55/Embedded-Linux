#include <iostream>
#include "seven_seg.h"



int main(int argc, char const *argv[])
{

    SevenSegment display({1, 2, 3, 4, 5, 6, 7}, std::cin, std::cout);

    display.write_digit(5);

    int x;
    display >> x;
    std::cout<< x << "\n";
    return 0;
}
