#!/bin/bash


qemu-system-aarch64 -M raspi3b \
	            -cpu cortex-a53 \
		    -m 1024 \
		    -kernel u-boot.bin \
		    -dtb bcm2837-rpi-3-b-plus.dtb \
		    -serial mon:stdio \
		    -device usb-kbd \
		    -net tap \
		    -net nic
