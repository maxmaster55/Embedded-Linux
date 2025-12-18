cmake_minimum_required(VERSION 3.19)


project(rpi_7seg C CXX)

add_executable( ${PROJECT_NAME}
    src/istream.cc  
    src/ostream.cc  
    src/seven_seg.cc  
    src/stream.cc
    app/main.cc
)

add_subdirectory(mypin)

target_include_directories(${PROJECT_NAME}
    PRIVATE inc
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE mypin
)

