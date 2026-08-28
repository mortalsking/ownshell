#include "shell.h"


//WRAPPERS


void Getcwd(char * buf,size_t size)
{
        // 1. IMPORTANT: getcwd grabs your current folder path (like /home/user) and stores it in 'buf'
        if(NULL == getcwd(buf,size))
                
                // 2. IMPORTANT: perror prints the exact system error if it fails (like if 'buf' is too small)
                perror(RED"getcwd FAILED"RST);
}
