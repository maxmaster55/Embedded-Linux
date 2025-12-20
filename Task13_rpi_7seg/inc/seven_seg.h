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
    bool active_high;
public:
    SevenSegment(std::array<int, 7> pins, bool active_high, std::istream& in, std::ostream& out);
    void write_digit(int digit) override;
    std::ostream& operator <<(int digit) override;
    std::istream& operator >>(int& digit) override;
    ~SevenSegment();
};

