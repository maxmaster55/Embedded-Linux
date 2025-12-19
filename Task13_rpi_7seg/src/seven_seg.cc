#include <seven_seg.h>

constexpr std::array<int, 10> seven_seg_lut = {
    0b00111111, // 0 → a b c d e f
    0b00000110, // 1 → b c
    0b01011011, // 2 → a b d e g
    0b01001111, // 3 → a b c d g
    0b01100110, // 4 → b c f g
    0b01101101, // 5 → a c d f g
    0b01111101, // 6 → a c d e f g
    0b00000111, // 7 → a b c
    0b01111111, // 8 → all
    0b01101111  // 9 → a b c d f g
};

SevenSegment::SevenSegment(std::array<int, 7> pins, std::istream& in, std::ostream& out)
:IStream(in), OStream(out)
{
    for (int i = 0; i < 7; i++)
    {
        if (pins[i] < 0)
        {
            throw std::invalid_argument("negative pin number");
        }

        hw_pins[i] = mypin(pins[i], mode_write);
    }



}


void SevenSegment::write_digit(int digit)
{
    if (digit > 9 || digit < 0) throw std::invalid_argument("invalid digit, use from 0 to 9");
    current_num = digit;

    for (int i = 0; i < 7; i++)
    {
        bool on = (seven_seg_lut[digit] >> i) & 0x1;
        hw_pins[i] << on;
    }
    
}

std::istream& SevenSegment::operator >>(int& digit)
{
    std::cout << "Please write the digit\n";
    in >> digit;
    return in;
}

std::ostream& SevenSegment::operator <<(int digit){
    write_digit(digit);
    out << "on the display now is: "<< digit << std::endl;
    return out;
}

SevenSegment::~SevenSegment()
{
    // do nothing i guess
}
