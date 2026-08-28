#ifndef SHELL_H // Include guard: Prevents this header file from being loaded more than once
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> // unistd.h: Provides access to standard OS system calls (like getcwd)

// ANSI Escape Codes: Special string sequences used to colorize terminal text
#define Y     "\033[1:33m" 
#define G     "\033[1:32m"
#define C     "\033[1:36m"
#define RED   "\033[1:31m"
#define RST   "\033[0m"    // RST: "Reset" - returns the terminal text color back to default


// Variadic macro: A shortcut that replaces 'p' with 'printf' and accepts any number of arguments
#define p(...) printf(__VA_ARGS__)

// Function prototype: Declares the function so other .c files know it exists before using it
void Getcwd(char *, size_t);


#endif
