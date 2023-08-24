.TH Shell(1) "22 August 2023" "Shell man page"

.SH NAME
.B Simple Shell
-

.SH SYNOPSIS
.RS hsh

.SH DESCRIPTION
.B Simple Shell
- is a command line interface or basic shell that allows users to interact with an operating system. It allows you to enter text commands to perform various tasks, such as managing files, running programs, and configuring settings on a computer system. The "Simple Shell" generally offers a limited set of features compared to more comprehensive command line interfaces, but still allows users to control and operate the computer through commands written in text.

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

.RS The output in a shell depends on the commands you enter and how the related functions and variables are implemented in the code.

    Program start:

ruby

($) 

    Example of executing an internal command (e.g., ls or cd):

shell

($) ls
file1 file2 file3
($) 

    Example of executing an existing and valid external command:

shell

($) echo "Hello, world!"
Hello, world!
($) 

    Example of executing an external command not found in the path:

ruby

($) command_not_found
./hsh: Command not found
($) 

    Example of executing an external command without execution permissions:

bash

($) ./my_script.sh
./hsh: ./my_script.sh: Permission denied
($) 

    If you press Ctrl+C during the execution of a command:

ruby

($) <You press Ctrl+C>
$

    If you enter an empty command and press Enter:

ruby

($) 
($) 


.SH AUTHORS

.RS Juan Silva / Oscar Morell:wq

