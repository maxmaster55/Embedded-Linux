#!/bin/bash


qemu-system-aarch64 -M raspi3b \
	            -cpu cortex-a53 \
				-m 1024 \
				-kernel u-boot.bin \
				-dtb bcm2837-rpi-3-b-plus.dtb \
				-device usb-kbd \
				-sd vsd.img \
				-serial file:kernel.log \
				-serial stdio \
				-monitor none
