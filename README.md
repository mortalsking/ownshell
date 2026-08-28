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
The "Work Smart" Guide: Building C Projects the Easy Way
When you are building a system-level project from scratch, typing out long C commands can get exhausting. Learn these "small things" to massively speed up your workflow:

Create a Custom Compile Shortcut
Stop typing gcc filename.c -o program every single time. Add a function like this to your ~/.bashrc file:

Bash
c() { gcc *.c -o "$1" && echo "✅ Compiled successfully!"; }
Now, you just type c shell and it compiles all your files instantly.

Use Macros to Save Keystrokes
C can feel repetitive, but you can mold it to your style. Just like how #define p(...) printf(__VA_ARGS__) makes printing as fast as Python, you can wrap complex error handling (like your Getcwd wrapper) into small, reusable chunks to keep your main code clean.

Master Your Editor Workflows
Whether you are configuring VS Code or using a terminal editor like Vim, learn to juggle multiple files smoothly. If using Vim, memorize jumping between files (Ctrl + ^ or :bn), and if you ever get a red .swp warning, remember to delete the hidden crash file (rm .filename.swp)!
