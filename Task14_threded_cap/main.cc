#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>
#include <chrono>

using namespace std::chrono_literals;

constexpr std::string_view FILE_PATH = "/sys/class/leds/input6::capslock/brightness";


void checker()
{
    static bool prev = false;

    std::fstream file(std::string(FILE_PATH), std::ios::in);

    if (!file)
    {
        std::cerr << "error, please use sudo\n";
        return;
    }

    std::string buffer;
    file >> buffer;

    bool curr = (buffer == "1");

    // Detect rising edge (OFF → ON)
    if (!prev && curr)
    {
        std::cout << "CapsLK pressed\n";
    }

    prev = curr;
}


void checker_loop()
{
    while (true)
    {
        checker();
         std::this_thread::sleep_for(10ms);
    }
}


int main(int argc, char const *argv[])
{
    std::thread th(checker_loop);


    th.join();
    return 0;
}
