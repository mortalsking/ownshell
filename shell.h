#ifndef SHELL_H // Include guard: Prevents this header file from being loaded more than once
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> // unistd.h: Provides access to standard OS system calls (like getcwd)

// ANSI Escape Codes: Special string sequences used to colorize terminal text
#define Y     "\033[1;33m" 
#define G     "\033[1;32m"
#define C     "\033[1;36m"
#define RED   "\033[1;31m"
#define RST   "\033[0m"    // RST: "Reset" - returns the terminal text color back to default


// Variadic macro: A shortcut that replaces 'p' with 'printf' and accepts any number of arguments
#define p(...) printf(__VA_ARGS__)
// DEL: A string of all the "whitespace" characters strtok will use to cut the input
#define DEL "\n\t \v\f\r"
// Function prototype: Declares the function so other .c files know it exists before using it
void Getcwd(char *, size_t);
void printbanner(void);

// FIXED: Added the prototypes you were missing from your previous steps!
void *Malloc(size_t size);
char *cell_read_line(void);
char **cell_split_line(char *line);

#endif
