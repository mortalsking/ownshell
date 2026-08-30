#include "shell.h"

char **cell_split_line(char *line)
{
        int bufsize = BUFSIZ; // FIXED: You must declare and set the initial size!
        char **tokens;
        int position = 0;

        // Allocating memory using your custom wrapper
        tokens = Malloc(BUFSIZ * sizeof *tokens);

        // Split the line into separate words
        for(char *token = strtok(line, DEL); token; token = strtok(NULL, DEL))
        {
                tokens[position++] = token;
                // If we've reached the current buffer size, double it and reallocate
                // memory for the tokens array to accommodate more elements.
                // NOTE: use realloc instead of malloc here, and fix the typo "bufize".

                if(position >= bufsize)
                {
                        bufsize *= 2;
                        tokens = malloc(tokens,bufsize * sizeof(*tokens));
                }
        }
        
        // The array MUST end with a NULL pointer so the OS knows when to stop reading
        tokens[position] = NULL; 

        return tokens; 
}
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
//the Printbanner prints the banner during the start of the shell for aesthetic view
 printbanner();
 char *line;
 // The loop continues automatically as long as the returned line is NOT NULL
 while(line = cell_read_line())
 {
  p("%s\n",line);
 }

return EXIT_SUCCESS; // Standard C macro (equal to 0) indicating a clean exit

}
