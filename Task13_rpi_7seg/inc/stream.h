#pragma once
#include <iostream>


class MyStream
{
private:
    std::string name;
public:
    MyStream(std::string name);
    virtual ~MyStream();
};
