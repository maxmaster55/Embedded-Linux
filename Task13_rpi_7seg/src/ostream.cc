#include <ostream.h>

OStream::OStream(std::ostream& out_stream): out(out_stream)
{
    std::cout<<"from OStream\n";
}


std::ostream& OStream::operator <<(std::string& outstring)
{
    /*read from fd the contents and save it in outstring */
    out << outstring;
    return out;
}


OStream::~OStream(){
    std::cout << "Ostrem Desctructor\n";
}