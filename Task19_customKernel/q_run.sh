#!/bin/bash

qemu-system-aarch64 \
    -M raspi3b \
    -cpu cortex-a53 \
    -m 1G \
	-nographic \
    -kernel u-boot.bin \
    -dtb bcm2837-rpi-3-b-plus.dtb \
    -sd vsd.img \
	-serial none \
    -serial stdio \
    -monitor none
