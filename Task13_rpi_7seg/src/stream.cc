#include <stream.h>


MyStream::MyStream(std::string name){
    std::cout<<"from Stream\n";
    this->name = name;
}


MyStream::~MyStream()
{
    std::cout << "Stream: "<< name <<" Desctructor\n";
}