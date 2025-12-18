#pragma once
#include <stream.h>


class IStream: virtual public MyStream
{
private:
    std::istream& in;
public:
    IStream(std::string name, std::istream& in_stream);
    std::istream& operator >>(int& digit);
    ~IStream();
};