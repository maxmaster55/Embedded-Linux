#include <vector>
#include <string>
#include <initializer_list>
#include <utility>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>


using std::vector;
using std::string;
using std::pair;
using std::initializer_list;

class FileActions
{
private:
    int* fd = new int;
    int*& fdRef = fd;
    vector<pair<string, int>> actions;
    
public:
    FileActions(string& path);
    FileActions(const FileActions& other);
    void registerActions(initializer_list<pair<string, int>> a_list);
    void excuteActions(string& on);
    ~FileActions();
};

