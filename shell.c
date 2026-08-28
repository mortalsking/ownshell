#include "shell.h"

 char *cell_read_line(void){
        char *buf;
        size_t bufsize;
        char cwd[BUFSIZ]; // BUFSIZ: A standard system value large enough to hold file paths
        buf = NULL;

        Getcwd(cwd,sizeof(cwd)); // Fetches your current directory path
        p(C"🤖 %s 🤖"RST"$>",cwd);
        
        // getline: Reads input from the keyboard (stdin) and automatically sizes memory
        if(getline(&buf,&bufsize,stdin) == -1)
        {
                // feof: Checks if the input failed because of "End Of File" (Ctrl+D)
                if(feof(stdin))
                {
                        p(RED"[EOF]"RST);
                        return NULL; // NULL acts as a signal to break the loop in main
                }
                else
                {
                        p(RED"Getline failed"RST);
                        return NULL;
                }

        }
        return buf;
 }

int main(){

 char *line;
 
 // The loop continues automatically as long as the returned line is NOT NULL
 while(line = cell_read_line())
 {
  p("%s\n",line);
 }

return EXIT_SUCCESS; // Standard C macro (equal to 0) indicating a clean exit

}
