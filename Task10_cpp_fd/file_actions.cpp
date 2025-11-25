#include "file_actions.h"


FileActions::FileActions(string& path){
    *fd = open(path.c_str(), O_RDWR);
    if (*fd == -1) {
        perror("open");
    }
}


FileActions::FileActions(const FileActions& other){
    actions = other.actions;
    fd = new int(*other.fd);
    fdRef = fd;
}


void FileActions::registerActions(initializer_list<pair<string, int>> a_list){
    for (auto element : a_list)
    {
        actions.push_back(element);
    }
    
}


void FileActions::excuteActions(string& on){

    for (auto &action : actions)
    {
        string str = action.first;
        int n = action.second;
        lseek(*fdRef, 0, SEEK_SET); // rewind to beginning
        if (str == "read") {
            std::cout << "reading " << n << " bytes.\n";

            string buffer;
            buffer.resize(n);

            ssize_t r = read(*fdRef, buffer.data(), n);
            if (r == -1) {
                perror("read");
                continue;
            }

            buffer.resize(r);
            on = buffer;
        }else if (str == "write")
        {
            std::cout << "writing "<< n << " bytes.\n"; 
            write(*fdRef, on.c_str(), n);
            write(*fdRef, "\n", 1);
        }else if (str == "close"){
            close(*fd);
        }else{
            std::cout << "What do you mean ¯\\_(ツ)_/¯ \n"; 
        }
    }
    
}


FileActions::~FileActions(){}