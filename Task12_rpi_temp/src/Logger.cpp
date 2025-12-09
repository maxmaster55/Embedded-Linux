#include "Logger.h"


void Logger::log_temperature(shared_ptr<TempData> td_ptr){
    static std::ofstream file("log.txt", std::ios::app); // append mode

    if (!file.is_open()) {
        throw std::runtime_error("Could not open log.txt");
    }

    std::string ts = std::ctime(&now);
    ts.pop_back();

    file <<"[" << ts <<"] the temperature is: " << td_ptr->read_temperature() << "\n";
    file.flush();
}


void Logger::log_humidity(shared_ptr<TempData> td_ptr){
    static std::ofstream file("log.txt", std::ios::app); // append mode

    if (!file.is_open()) {
        throw std::runtime_error("Could not open log.txt");
    }

    std::string ts = std::ctime(&now);
    ts.pop_back();
    file <<"[" << ts <<"] the humidity is: " << td_ptr->read_humidity() << "\n";
    file.flush();
}

