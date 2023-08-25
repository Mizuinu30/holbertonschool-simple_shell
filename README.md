[![Holberton](https://media.licdn.com/dms/image/D4E3DAQELF0oHsdXo5Q/image-scale_191_1128/0/1686597001135?e=1693206000&v=beta&t=5I1Uj7fzOIGQ_4QWXjkmohsDmTElKMS4Q4xn8mXT96s "Holberton")](htthttps://media.licdn.com/dms/image/D4E3DAQELF0oHsdXo5Q/image-scale_191_1128/0/1686597001135?e=1693206000&v=beta&t=5I1Uj7fzOIGQ_4QWXjkmohsDmTElKMS4Q4xn8mXT96sp:// "Holberton")


## C - Simple Shell

[![shell](https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/holbertonschool-low_level_programming/235/shell.jpeg "shell")](http://https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/holbertonschool-low_level_programming/235/shell.jpeg "shell")
####  Description
<p>
In this project we are creating our own simple UNIX command interpreter. The program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0].
Usage
</p>
```
    Enter custom shell by typing "./hsh". You should be prompted with a ($).
    Type a command of your liking and press "Enter".
    Appropriate output will appear.
    Prompt reappears and awaits your next command.
    Exit shell by typing "exit"
```

#### Compilation

**Your shell will be compiled this way:**
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

#### Testing

**Your shell should work like this in interactive mode:**
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

**But also in non-interactive mode:**
```
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
```

#### Repo:
```
    GitHub repository: holbertonschool-simple_shell
    File: README.md, man_1_simple_shell, AUTHORS
```

#### Tasks

**0. README, man, AUTHORS**

- Write a README
- Write a man for your shell.
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker



**1. Betty would be proud**

- Write a beautiful code that passes the Betty checks



**2. Simple shell 0.1**

###### Write a UNIX command line interpreter.

- Usage: simple_shell

###### Your Shell should:

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
    Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)

###### You don’t have to:

- use the PATH
- implement built-ins
- handle special characters : ", ', `, \, *, &, #
- be able to move the cursor
- handle commands with arguments

###### execve will be the core part of your Shell, don’t forget to pass the environ to it…


**3. Simple shell 0.2**

###### Simple shell 0.1 +

- Handle command lines with arguments


**4. Simple shell 0.3**

###### Simple shell 0.2 +

- Handle the PATH
- fork must not be called if the command doesn’t exist


**5. Simple shell 0.4**

###### Simple shell 0.3 +

- Implement the exit built-in, that exits the shell
- Usage: exit
- You don’t have to handle any argument to the built-in exit


**6. Simple shell 1.0**

###### Simple shell 0.4 +

- Implement the env built-in, that prints the current environment


#### Example:

###### Here is an example of what the output in the shell during an interactive session might look like:
```
($)
($) ls
file1.txt file2.txt
($) pwd
/home/user
($) cd /usr/bin
($) ls
ls mkdir cat
($) exit
```
###### In this example:
```
The shell is started, indicated by the initial prompt ($).
The command ls is entered, which displays the files file1.txt and file2.txt.
The command pwd is entered, which displays the current working directory as /home/user.
The command cd /usr/bin is entered to change the current directory to /usr/bin.
The command ls is entered again, showing the contents of the /usr/bin directory as ls mkdir cat.
Finally, the exit command is entered to exit the shell.
```

#### Authors:

Oscar Morell <oscarmorell07@yahoo.com>

Juan Silva <juansilva.dvm@gmail.com>



