# how to use

first compile the shared object
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