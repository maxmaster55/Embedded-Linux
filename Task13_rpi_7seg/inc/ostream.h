#pragma once
#include <stream.h>

class OStream: virtual public MyStream
{
private:
    std::ostream& out;
public:
    OStream(std::string name, std::ostream& out_stream);

    std::ostream& operator <<(std::string& outstring);
    ~OStream();
};
