#include "BCM2837.h"

typedef unsigned int uint;

void write32(void *dst, uint val) { *(volatile uint *)dst = val; }

uint read32(void *src) { return *(volatile uint *)src; }

void main(void) {
  uint gpfsel2;

  // Configure pin 21 as output
  gpfsel2 = read32((void *)BCM2837_GPFSEL2);
  gpfsel2 |= (1 << 3); // Set bits 3-5 to 001 for output
  write32((void *)BCM2837_GPFSEL2, gpfsel2);

  volatile int i = 0; // volatile prevents optimization

  while (1) {
    // Turn on pin 21
    write32((void *)BCM2837_GPSET0, 1 << 21);

    // Delay
    i = 0;
    while (i < 100000000) {
      i++;
    }

    // Turn off pin 21
    write32((void *)BCM2837_GPCLR0, 1 << 21);

    // Delay
    i = 0;
    while (i < 100000000) {
      i++;
    }
  }
}