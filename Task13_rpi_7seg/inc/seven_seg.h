#pragma once
#include <istream.h>
#include <ostream.h>
#include <mypin.h>
#include <array>



class SevenSegment: virtual public IStream, virtual public OStream
{
private:
    int current_num;
    std::array<mypin, 7> hw_pins;
public:
    SevenSegment(std::array<int, 7> pins, std::istream& in, std::ostream& out);
    void write_digit(int digit);
    ~SevenSegment();
};

