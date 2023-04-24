#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
char *_itoa(int n);
char *_uitoa(unsigned int n);
char *_uitoa_base(unsigned int n, unsigned int base);
int print_int_helper(int n);
int print_int(va_list args);

#endif
