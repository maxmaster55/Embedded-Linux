#include <iostream>
#include <thread>
#include <chrono>
#include "seven_seg.h"

using std::this_thread::sleep_for;
using std::chrono::seconds;

int main(int argc, char const *argv[])
{
    try
    {
        SevenSegment display({2, 3, 9, 17, 27, 22, 10}, false, std::cin, std::cout);
        while (true)
        {
            int digit;

            // read the digit first, then display it
            display >> digit;
            // stop on input failure (e.g. EOF)
            if (!std::cin) break;
            display << digit;
            sleep_for(seconds(1));
        }
    }

    catch(const std::exception& e)
    {   
        std::cerr << "damn you on your own ¯\\_(ツ)_/¯.\n";
        std::cerr << e.what() << '\n';
    };
    

    return 0;
}
