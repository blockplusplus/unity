#include "mbed.h"

RawSerial pc(USBTX, USBRX);

void mbed_console_putc(int a) {
    pc.putc(a);
}
