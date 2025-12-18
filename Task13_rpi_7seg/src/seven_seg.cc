#include <seven_seg.h>



SevenSegment::SevenSegment(std::string name, std::istream& in, std::ostream& out)
: MyStream(name), IStream(name, in), OStream(name, out)
{

}


void SevenSegment::write_digit(int digit)
{

}


SevenSegment::~SevenSegment()
{
}
