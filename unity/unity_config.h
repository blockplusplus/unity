#ifndef UNITY_CONFIG_H
#define UNITY_CONFIG_H

void mbed_console_putc(int);

#define UNITY_OUTPUT_CHAR(a)    mbed_console_putc(a)

#endif