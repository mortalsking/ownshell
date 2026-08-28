#include<shell.h>

char *cell_read_line(void){
        char *buf;        // Pointer to hold the text the user types
        size_t bufsize;   // Tracks the size of the allocated memory
        char cwd[BUFSIZ]; // Buffer for current directory (unused right now)
        
        buf = NULL;       // Set to NULL so getline automatically allocates memory for us

        p("$<");         
        
     
        // If it returns -1, something went wrong or ended.
        if(getline(&buf, &bufsize, stdin) == -1) 
        {
                
                if(feof(stdin)) 
                  p(RED"[EOF]"RST);          
                else
                  p(RED"Getline failed"RST);
        }
        
        return buf;       
}

int main(int ac,char **av){

 char *line;     

 while(0xcE88)    
 {
  line = cell_read_line(); 
  
  p("%s\n", line);        
 }

 return EXIT_SUCCESS;     
}
