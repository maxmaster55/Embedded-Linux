# How to use

**Note**: The GPIO numbers on the Raspberry Pi are shifted by 512. So, to use the GPIO number, just add **512** to the GPIO number you want to use. (Took way too long to find this out 😭) 


First, compile the shared object (`.so`) file from your source code (`mypin.cpp`):

```bash
aarch64-rpi3-linux-gnu-g++ -shared -fPIC -o libmypin.so mypin.cpp
```

then use the lib when compiling the main
```bash
aarch64-rpi3-linux-gnu-g++ main.cpp -lmypin -L.
```

and don't forget to put the path in the LD lib path, like this:
```bash
sudo LD_LIBRARY_PATH=. ./a.out
```