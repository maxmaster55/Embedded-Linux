#include "Logger.h"


void Logger::logTemp(shared_ptr<TempData> td_ptr){
    static std::ofstream file("log.txt", std::ios::app); // append mode

    if (!file.is_open()) {
        throw std::runtime_error("Could not open log.txt");
    }

    file << "the temp is: " << td_ptr->read_temp() << "\n";
    file.flush();
}

