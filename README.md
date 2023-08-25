Holberton School
0x16. C - Simple Shell
Description

In this project we are creating our own simple UNIX command interpreter. The program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0].
Usage

    Enter custom shell by typing "./hsh". You should be prompted with a ($).
    Type a command of your liking and press "Enter".
    Appropriate output will appear.
    Prompt reappears and awaits your next command.
    Exit shell by typing "exit"


Compilation

Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Testing

Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$


Tasks
0. README, man, AUTHORS


    Write a README
    Write a man for your shell.
    You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker


Example:

Here is an example of what the output in the shell during an interactive session might look like:

($)
($) ls
file1.txt file2.txt
($) pwd
/home/user
($) cd /usr/bin
($) ls
ls mkdir cat
($) exit

In this example:

    The shell is started, indicated by the initial prompt ($).

    The command ls is entered, which displays the files file1.txt and file2.txt.

    The command pwd is entered, which displays the current working directory as /home/user.

    The command cd /usr/bin is entered to change the current directory to /usr/bin.

    The command ls is entered again, showing the contents of the /usr/bin directory as ls mkdir cat.

    Finally, the exit command is entered to exit the shell.

Authors:

Oscar Morell <oscarmorell07@yahoo.com>
Juan Silva <juansilva.dvm@gmail.com>
