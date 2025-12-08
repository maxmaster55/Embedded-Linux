cmake_minimum_required(VERSION 3.10)

# Project name and language
project(TemperatureProject LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Collect source files
set(SOURCES
    src/main.cpp
    src/Display.cpp
    src/LM_Sensor.cpp
    src/Logger.cpp
    src/TempDate.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})
