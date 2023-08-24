.TH Shell "22 August 2023" "Shell man page"

.SH NAME
.B Simple Shell
-

.SH SYNOPSIS
hsh

.SH DESCRIPTION
.B Simple Shell
- is a command line interface or basic shell that allows users to interact with an operating system. It allows you to enter text commands to perform various tasks, such as managing files, running programs, and configuring settings on a computer system. The "Simple Shell" generally offers a limited set of features compared to more comprehensive command line interfaces, but still allows users to control and operate the computer through commands written in text.

.SH OBJECTIVE

.RS
Code is intended to create a basic shell environment where users can enter commands, and the program executes them in child processes, providing an experience similar to that of a shell on an operating system.

.SH TOKENIZE
This function takes a string (a line of input) and splits it into individual tokens (words/arguments). It uses spaces, tabs, and newline characters as delimiters to separate tokens. The tokens are stored in a dynamically allocated array of strings.

.SH MAIN FUNCTION

.RS The program enters an infinite loop to keep accepting user input.
    It prompts the user with a $> symbol.
    It reads user input using fgets and removes the newline character at the end.
    It forks a new process using fork(). The child process is used to execute the command, while the parent process waits for the child to complete.
    In the child process, the input string is tokenized using the tokenize function.
    The execve function is called to replace the child process's memory with the specified command. If the execution fails, an error message is printed.
    After command execution, memory allocated for tokens is freed.
    In the parent process, it waits for the child process to complete using waitpid. If the waiting fails, an error message is printed.

.SH MEMORY MANAGEMENT

.RS One thing to note is that the memory allocated for tokens in the tokenize function and the token array in the main loop must be freed to prevent memory leaks. The code does this correctly, freeing all allocated memory before the child process finishes and after the parent process waits for it to complete.

.SH COMMANND EXECUTION

.RS The execve function is used to execute the given command. It replaces the current process image with the new command's image. If the execution fails, an error message is printed using perror.

.SH EXAMPLES

.RS If you enter a valid command (for example, ls), the program should run the command in a child process and display the output of the command. For example: 

.br shell
.br $>ls
.br file1 file2
.br $>

.RS If you enter the exit command, the program should end and the exit from the program will simply be a return to the operating system:

.br shell
.br $>exit
.br $

.RS The exact output may vary depending on your system configuration and how it handles signals and errors. 

.SH AUTHORS

.RS Juan Silva / Oscar Morell
