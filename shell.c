#include "shell.h"

char *cell_read_line(void){
        char *buf;
        size_t bufsize;

        buf = NULL; // Let getline handle memory size automatically

        // Read a line of text typed by the user
        if(getline(&buf, &bufsize, stdin) == -1)
        {
                // If the user pressed Ctrl+D (End of File)
                if(feof(stdin))
                  p(RED"[EOF]"RST);
                else
                  p(RED"Getline failed"RST);
        }

        return buf; 
}

int main(int ac, char **av){
 char *line;
 
 
 while(0xcE88) 
 {
  // Wait for the user to type something and save it in 'line'
  line = cell_read_line();
 }

 return EXIT_SUCCESS;
}
