#include "mbed.h"

RawSerial pc(USBTX, USBRX);

extern "C" void mbed_console_putc(int);
void mbed_console_putc(int a) {
    pc.putc(a);
}
