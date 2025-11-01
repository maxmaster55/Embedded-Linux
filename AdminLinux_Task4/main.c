#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <1 to turn on, 0 to turn off>\n", argv[0]);
        return 1;
    }


    int option = atoi(argv[1]);
    int fd = open("/sys/class/leds/input9::capslock/brightness", O_RDWR);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }
    

    if (option == 1) {
        write(fd, "1", 2); // Turn on Caps Lock LED
    } else if (option == 0) {
        write(fd, "0", 2); // Turn off Caps Lock LED
    } else {
        printf("Invalid option. Use 1 to turn on and 0 to turn off.\n");
    }


    return 0;
}