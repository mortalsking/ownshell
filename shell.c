#include <shell.h> // Includes necessary functions for the program to run

int main(int ac, char **av) {

    // We aren't using the 'ac' (argument count) variable in this code.
    // This line tells the compiler to ignore it so we don't get an "unused variable" warning.
    (void)ac; 
    
    // This variable will hold the "exit status" (success or failure) of the child process.
    int status; 
    
    // fork() creates an exact copy of this program (called a "child" process).
    // When fork() returns 0, it means we are currently executing inside that new child process.
    if (fork() == 0) {
        
        // execvp replaces this child process with a brand new command/program.
        // av[1] is the name of the command to run (like "ls" or "echo").
        // av+1 passes the rest of the arguments to that command.
        execvp(av[1], av + 1); 
    }
    
    // The original "parent" process skips the 'if' block and comes down here.
    // wait() makes the parent pause and wait for the child process to completely finish.
    wait(&status); 
    
    // The program finishes and exits successfully!
    return EXIT_SUCCESS; 
}
