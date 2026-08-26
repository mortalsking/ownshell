/* 1. These top two lines prevent this file from being loaded twice by accident. */
#ifndef SHELL_H
#define SHELL_H

/* 2. Pulling in standard C toolboxes (libraries) you need to build a shell. */
#include<stdio.h>  
#include<stdlib.h> 
#include<unistd.h> 

/* 3. Setting up color shortcuts using "ANSI escape codes". */
#define Y     "\033[1:33m"  // Yellow text
#define G     "\033[1:32m"  // Green text
#define C     "\033[1:36m"  // Cyan (light blue) text
#define RED   "\033[1:31m"  // Red text
#define RST   "\033[0m"     // Reset (turns the color back to normal)

/* 4. A lazy shortcut! */
#define p(...) printf(__VA_ARGS__)

/* 5. This closes the "#ifndef" check from the very top of the file. */
#endif
