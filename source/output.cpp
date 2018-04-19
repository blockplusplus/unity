#include "mbed.h"

RawSerial pc(USBTX, USBRX);

extern "C" void mbed_console_putc(int);
void mbed_console_putc(int a) {
    pc.putc(a);
}

extern "C" void mbed_console_setup();
void mbed_console_setup() {
    pc.baud(9600);
    pc.format();
}

extern "C" void mbed_console_newline();
void mbed_console_newline() {
    pc.puts("\r\n");
}
