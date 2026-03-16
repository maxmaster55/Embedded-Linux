#!/bin/bash


# num is the number printed at the top of qemu
# use this picocom -b 115200 /dev/pts/{num}
# working bootargs: setenv bootargs "console=ttyAMA0,115200 console=tty1 root=/dev/mmcblk0p2 rootwait rw"
 
qemu-system-aarch64 \
    -M raspi3b \
    -cpu cortex-a53 \
    -m 1G \
    -kernel u-boot.bin \
    -dtb bcm2837-rpi-3-b-plus.dtb \
    -sd vsd.img \
	-nographic \
	-serial pty \
	-serial mon:stdio 


