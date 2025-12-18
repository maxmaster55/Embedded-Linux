#include <iostream>
#include "stream.h"
#include "istream.h"
#include "ostream.h"


int main(int argc, char const *argv[])
{

    OStream to("test_out", std::cout);
    IStream from("test_in", std::cin);

    int x = 6;

    from >> x;

    auto str = std::to_string(x);

    to << str << std::endl;
    return 0;
}
