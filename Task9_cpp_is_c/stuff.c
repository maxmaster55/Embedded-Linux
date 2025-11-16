#include <stdio.h>

#ifdef __cplusplus
namespace stuff
{
#endif

void print_message(const char* message){
    printf("The message is: %s\n", message);
}

void print_number(int number){
    
    printf("Your favourite number is: %d\n", number);
}

#ifdef __cplusplus
} 
#endif