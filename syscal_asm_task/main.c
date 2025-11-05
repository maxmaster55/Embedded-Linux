#define stdout 1


void my_print(const char *text, int len);
void my_write(unsigned int fd, const char *buf,	int count);

int main() {
 

    char to_print[] = "Hello World\n";

    my_print(to_print, 12);

    return 0;
}


void my_write(unsigned int fd, const char *buf, int count) {
    asm volatile(
        "mov $1, %%rax\n\t"   // syscall number (1 = write)
        "mov %0, %%edi\n\t"   // fd
        "mov %1, %%rsi\n\t"   // buf
        "mov %2, %%edx\n\t"   // count
        "syscall\n\t"         // make the syscall
        :                     // for outputs
        : "r"(fd), "r"(buf), "r"(count) // inputs
    );
    
}


void my_print(const char *text, int len){

    my_write(stdout, text, len);
    
}
