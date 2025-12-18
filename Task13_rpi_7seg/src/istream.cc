#include <istream.h>



IStream::IStream(std::string name, std::istream& in_stream)
    :MyStream(name),
    in(in_stream)
{
    std::cout<<"from IStream\n";
}


std::istream& IStream::operator >>(int& digit)
{
    std::cout << "Please write the digit\n";
    in >> digit;
    /*write on fd*/
    return in;
}


IStream::~IStream(){
    std::cout << "IStream Desctructor \n";
}