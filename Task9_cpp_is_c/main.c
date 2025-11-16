#include "stuff.h"

#ifdef __cplusplus
using namespace stuff;
#endif

int main(void)
{
    #ifdef __cplusplus
    print_message("Hello C++");
    print_number(11);
    #else
    print_message("Hello C");
    print_number(99);
    #endif

    return 0;
}
