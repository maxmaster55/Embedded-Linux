#pragma once
#include <istream.h>
#include <ostream.h>



class SevenSegment: virtual public IStream, virtual public OStream
{
private:
    /* data */
public:
    SevenSegment(std::string name, std::istream& in, std::ostream& out);
    void write_digit(int digit);
    ~SevenSegment();
};

