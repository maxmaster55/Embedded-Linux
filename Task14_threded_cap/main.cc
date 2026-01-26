#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std::chrono_literals;

constexpr std::string_view FILE_PATH = "/sys/class/leds/input6::capslock/brightness";


std::mutex mx;
std::condition_variable cv;
bool caps_pressed = false;

void checker()
{
    static bool prev = false;

    std::ifstream file(FILE_PATH.data());
    if (!file) return;

    std::string buffer;
    file >> buffer;

    bool curr = (buffer == "1");

    if (!prev && curr) {
        std::lock_guard<std::mutex> lock(mx);
        caps_pressed = true;
    }
    cv.notify_one();

    prev = curr;
}


void listener()
{
    std::unique_lock<std::mutex> lock(mx);

    while (true) {
        cv.wait(lock, [] { return caps_pressed; });

        std::cout << "CapsLK pressed\n";

        caps_pressed = false;
    }
}


void checker_loop()
{
    while (true)
    {
        checker();
         std::this_thread::sleep_for(10ms);
    }
}

int main()
{
    std::thread t1(checker_loop);
    std::thread t2(listener);

    t1.join();
    t2.join();
}
