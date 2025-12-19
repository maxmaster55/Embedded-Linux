#include <istream.h>



IStream::IStream(std::istream& in_stream): in(in_stream)
{
    std::cout<<"from IStream\n";
}


std::istream& IStream::operator >>(int& digit)
{
    std::cout << "Please write the digit\n";
    in >> digit;
    return in;
}


IStream::~IStream(){
    std::cout << "IStream Desctructor \n";
}