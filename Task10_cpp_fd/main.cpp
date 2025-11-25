#include "file_actions.h"

/**
 * @note with read the int is n bytes to read
 *       with write the int is n bytes to write
 *       with close it is useless ¯\_(ツ)_/¯
 */

int main(){
    string x = "test.txt";
    FileActions f(x);
    f.registerActions({
        pair("write",2),
        pair("read",2),
        pair("close",0)
    });
    
    string t = "hi";
    f.excuteActions(t);
    std::cout<< "val is: " << t << "\n";
}