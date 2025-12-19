#include <ostream.h>

OStream::OStream(std::ostream& out_stream): out(out_stream)
{
    std::cout<<"from OStream\n";
}


std::ostream& OStream::operator <<(int digit)
{
    out << digit;
    return out;
}


OStream::~OStream(){
    std::cout << "Ostrem Desctructor\n";
}