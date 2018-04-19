#ifndef UNITY_CONFIG_H
#define UNITY_CONFIG_H

void mbed_console_putc(int);
void mbed_console_setup();
void mbed_console_newline();


#define UNITY_INT_WIDTH  32
#define UNITY_LONG_WIDTH 32

#define UNITY_OUTPUT_CHAR(a)    mbed_console_putc(a)
#define UNITY_OUTPUT_START()    mbed_console_setup()
#define UNITY_PRINT_EOL()       mbed_console_newline()

#endif