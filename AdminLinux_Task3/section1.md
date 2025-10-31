## Task one explanation

- when the new terminal is opened if ``` .bashrc ``` is found:
  - The local variable ```LOCAL``` will not be inherited due to being a local var defined without the word ```export```
  - The global variable will exist in it because the syscall ```mmap``` will copy all the global vars to the opened process.