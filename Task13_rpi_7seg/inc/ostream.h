#pragma once
#include <stream.h>

class OStream: virtual public MyStream
{
protected:
    std::ostream& out;
public:
    OStream(std::ostream& out_stream);
    virtual void write_digit(int digit) = 0;
    virtual std::ostream& operator <<(int digit);
    ~OStream();
};
