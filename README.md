# OwnShell
A basic command-line shell written in C, featuring custom color macros and user input reading.

🚀 How to Run It
Make sure both shell.h and main.c are in the same folder.

Open your terminal (like in VS Code).

Compile the code using GCC:

Bash
gcc main.c -o my_shell
Run the program:

Bash
./my_shell
(Note: Since it is an infinite loop, press Ctrl + C in your terminal to force it to quit).

📚 Library Knowledge
Here is why we included those three specific headers:

<stdio.h> (Standard Input/Output): Handles reading and writing. It gives us printf (used in your p macro), stdin (your keyboard), and the getline() function to read text.

<stdlib.h> (Standard Library): Handles memory. When you set buf = NULL, stdlib steps in to automatically give getline the right amount of memory to store the user's text. It also gives us EXIT_SUCCESS.

<unistd.h> (Unix Standard): Connects your C code to the Unix/Linux operating system. You aren't using its full power yet, but you will need it later for system calls like fork() and execvp() to actually execute the commands the user types.

🧠 Where to Learn More
If you want to understand the exact mechanics of building a shell in C, check these out:

Stephen Brennan's "Write a Shell in C": This is the most famous, easy-to-read blog post for this exact project. Just Google "Stephen Brennan write a shell" and read through it. It explains getline, fork, and exec perfectly.

Linux Man Pages: If you ever want to know exactly how a function works, just type man getline or man 3 printf right into your terminal. It is the official manual.

GeeksforGeeks: Search for topics like "Dynamic Memory Allocation in C" to better understand how char *buf and size_t work under the hood.
