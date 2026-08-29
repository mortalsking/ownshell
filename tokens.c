#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define p(...) printf(__VA_ARGS__)

// The characters we use to split the string
#define DEL " "

void cell_split_line(char *line)
{
        // Creates an array for 6 words and sets them all to NULL
        char *tokens[6] = {0};
        int position = 0;

        // strtok cuts the string into pieces every time it sees a space.
        // It keeps running until it runs out of words (token becomes NULL).
        for(char *token = strtok(line,DEL); token; token=strtok(NULL,DEL))
        {
                tokens[position++] = token;
        }
        
        position = 0;
        
        // Prints words one by one until it hits the empty NULL slot
        while(tokens[position])
                p("%s\n",tokens[position++]);
}

int main(void)
{
        // Using char s[] allows strtok to modify the string. 
        // (Using char *s would cause a crash!)
        char s[] = "ls -la file.txt | cat";
        
        cell_split_line(s);

        return EXIT_SUCCESS; 
}
