#!/bin/bash

 
sudo qemu-system-arm \
        -M vexpress-a9 \
        -m 1G \
        -kernel u-boot \
        -dtb vexpress-v2p-ca9.dtb \
        -sd vsd.img \
        -nographic \
        -net tap,script=./qemu-ifup -net nic


