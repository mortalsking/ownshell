# OwnShell
A basic command-line shell written in C, featuring custom color macros, a custom ASCII boot banner, and dynamic user input reading.

## 🚀 How to Run It

1. Make sure all your `.c` and `.h` files (like `shell.h` and `shell.c`) are in the same folder.
2. Open your terminal (like in VS Code).
3. Compile the code using GCC:
   ```bash
   gcc *.c -o my_shell
   ```
4. Run the program:
   ```bash
   ./my_shell
   ```
*(Note: Since it is an infinite loop, press `Ctrl + D` or `Ctrl + C` in your terminal to safely exit).*

---

## 📚 Library Knowledge

Here is why we included those specific headers:

* **`<stdio.h>` (Standard Input/Output):** Handles reading and writing. It gives us `printf` (used in your `p` macro), `stdin` (your keyboard), and the `getline()` function to read text.
* **`<stdlib.h>` (Standard Library):** Handles memory. When you set `buf = NULL`, `stdlib` steps in to automatically give `getline` the right amount of memory to store the user's text. It also gives us `EXIT_SUCCESS`.
* **`<unistd.h>` (Unix Standard):** Connects your C code to the Unix/Linux operating system. You aren't using its full power yet, but you will need it later for system calls like `fork()` and `execvp()` to actually execute the commands the user types.

## 🧠 Where to Learn More

If you want to understand the exact mechanics of building a shell in C, check these out:

* **Stephen Brennan's "Write a Shell in C":** This is the most famous, easy-to-read blog post for this exact project. Just Google "Stephen Brennan write a shell" and read through it. It explains `getline`, `fork`, and `exec` perfectly.
* **Linux Man Pages:** If you ever want to know exactly how a function works, just type `man getline` or `man 3 printf` right into your terminal. It is the official manual.
* **GeeksforGeeks:** Search for topics like "Dynamic Memory Allocation in C" to better understand how `char *buf` and `size_t` work under the hood.

---

## 🛠️ The "Work Smart" Guide: Building C Projects the Easy Way

When you are building a system-level project from scratch, typing out long C commands can get exhausting. Learn these "small things" to massively speed up your workflow:

### 1. Create a Custom Compile Shortcut
Stop typing `gcc filename.c -o program` every single time. Add a function like this to your `~/.bashrc` file:

```bash
c() { gcc *.c -o "$1" && echo "✅ Compiled successfully!"; }
```
Now, you just type `c shell` and it compiles all your files instantly.

### 2. Use Macros to Save Keystrokes
C can feel repetitive, but you can mold it to your style. Just like how `#define p(...) printf(__VA_ARGS__)` makes printing as fast as Python, you can wrap complex error handling (like your `Getcwd` wrapper) into small, reusable chunks to keep your main code clean.

### 3. Master Your Editor Workflows
Whether you are configuring VS Code or using a terminal editor like Vim, learn to juggle multiple files smoothly. If using Vim, memorize jumping between files (`Ctrl + ^` or `:bn`), and if you ever get a red `.swp` warning, remember to delete the hidden crash file (`rm .filename.swp`)!

## Deep Dive: Tokenizing and Memory Management

When building a shell, reading the text is only half the battle. You have to break that text down and manage the memory dynamically. Here is how `cell_split_line` works:

### 1. What is a Token?
If a user types `ls -l /tmp`, the OS doesn't understand that as one giant string. It needs an array of individual words (strings). We use `strtok` (String Tokenizer) to cut the input string every time it sees a space. 
* Token 0: `ls`
* Token 1: `-l`
* Token 2: `/tmp`

### 2. The `char **tokens` Array
Why two asterisks (`**`)? 
* A `char *` is a pointer to a string (one word).
* A `char **` is a pointer to an *array* of strings. We need an array of words to pass to the operating system.

### 3. Why we use `realloc`
We start by making our `tokens` array large enough to hold `BUFSIZ` words (usually a few thousand bytes). But what if a user pastes a massive command with 10,000 words? 
If we hardcoded the size (e.g., `char *tokens[100]`), the shell would crash (Segmentation Fault). 

Instead, we use a dynamic doubling strategy:
1. Track how many tokens we have (`position`).
2. If `position` hits our limit (`bufsize`), we multiply the limit by 2 (`bufsize *= 2`).
3. We call `realloc()`. This tells the OS: *"Take my existing array, find a bigger space in memory, copy my old words over, and give me the extra space at the end."*

This guarantees our shell will never crash from an input being "too long".
