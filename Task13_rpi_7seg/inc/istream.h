#pragma once
#include <stream.h>


class IStream: virtual public MyStream
{
protected:
    std::istream& in;
public:
    IStream(std::istream& in_stream);
    virtual std::istream& operator >>(std::string& digit);
    ~IStream();
};