qemu-system-aarch64 \
    -M raspi3b \
    -cpu cortex-a53 \
    -m 1G \
    -kernel Image \
    -dtb bcm2710-rpi-3-b-plus.dtb \
    -sd sdcard.img \
    -nographic \
    -monitor none \
    -append "root=/dev/mmcblk0p2 rootwait rw console=ttyAMA0,115200 earlycon=pl011,0x3f201000 loglevel=8"
