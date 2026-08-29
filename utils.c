#include "shell.h"


//WRAPPERS


void Getcwd(char * buf,size_t size)
{
        // 1. IMPORTANT: getcwd grabs your current folder path (like /home/user) and stores it in 'buf'
        if(NULL == getcwd(buf,size))
                
                // 2. IMPORTANT: perror prints the exact system error if it fails (like if 'buf' is too small)
                perror(RED"getcwd FAILED"RST);
}
void *Malloc(size_t size)
{
        void *ptr;
        
        // Safety check: If asked for 0 bytes, just return NULL safely
        if(size == 0)
                return(NULL);
        
        // Attempt to allocate the memory
        ptr = malloc(size);
        
        // If malloc fails (e.g., out of RAM), print error and kill the program immediately
        if(!ptr)
        {
                perror(RED"Malloc failed"RST);
                exit(EXIT_FAILURE); // Forces the program to quit safely
        }
        return (ptr);
}
//printbanner is used for the banner of shell v.! .
void printbanner(void) {
    p(Y" ██████╗ ██╗    ██╗███╗   ██╗███████╗██╗  ██╗███████╗██╗     ██╗         ██╗   ██╗  ██╗\n"
       "██╔═══██╗██║    ██║████╗  ██║██╔════╝██║  ██║██╔════╝██║     ██║         ██║   ██║ ███║\n"
       "██║   ██║██║ █╗ ██║██╔██╗ ██║███████╗███████║█████╗  ██║     ██║         ██║   ██║ ╚██║\n"
       "██║   ██║██║███╗██║██║╚██╗██║╚════██║██╔══██║██╔══╝  ██║     ██║         ╚██╗ ██╔╝  ██║\n"
       "╚██████╔╝╚███╔███╔╝██║ ╚████║███████║██║  ██║███████╗███████╗███████╗     ╚████╔╝██╗██║\n"
       " ╚═════╝  ╚══╝╚══╝ ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝      ╚═══╝ ╚═╝╚═╝\n\n"RST);
}
