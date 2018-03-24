## Simple Shell
> In this project, we coded from scatch a simple Unix shell. A shell is an interactive 
> command-line interface (CLI). It allows users to type in commands and have the
> operating system respond back. It is slightly different from a graphical user
> interface (GUI). Instead of using a mouse to click to open and delete files, a user
> can type in a command (e.g. "ls" or "rm") and have the files be displayed or
> modified in a list on the command line. They both have the same purpose to interact
> with the operating system but their input methods are different. There are a few
> versions of Unix shells, from the very first (Ken Thompson's) shell that can
> be activated by typing ```sh``` in the terminal and today's most popular Bash
> (Bourne Again Shell).

### Synopsis
> This repository holds all the code necessary for our custom simple shell to run.
> Our shell currently handles the executions of shell builtins found in the
> environmental variable PATH, with or without their full paths. Sample commands
> our shell supports include ```ls``` (```/bin/ls```), ```pwd```, ```echo```,
> ```which```, ```whereis```, etc. It also handles the executions of ```exit```
> ```env```. To read more on how our shell works behind the scenes, visit our
> blog at ____________.         

### Description of what each file shows:
```
man_3_shell ------------------------ custom manpage for our simple shell
main.c ----------------------------- holds entrance into program
shell.h ---------------------------- holds prototypes of functions spread across all files
          
```
### Environment
* Language: C
* OS: Ubuntu 14.04 LTS
* Compiler: gcc 4.8.4
* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

### How To Install, Compile, and Use
Install and Compile
```
(your_terminal)$ git clone https://github.com/MelissaN/simple_shell.git
(your_terminal)$ cd simple_shell
(your_terminal)$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o simple_shell
```
Activate the shell
```
(your_terminal)$ ./simple_shell
$
```
Sample Usage
```
$ ls
yourfile.c yourprogram.o
$ echo "This is a pretty cool!"
This is pretty cool!
```
Stop and return to your original shell
```
$ exit
(your_terminal)$
```

### To Do
* More functionality can still be added (e.g. handle pipelines and redirections)

---
### Authors
Kevin Yook [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/30px-Twitter_Bird.svg.png)](https://twitter.com/yook00627)
Melissa Ng [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/30px-Twitter_Bird.svg.png)](https://twitter.com/MelissaNg__)

### License
[![M](https://www.holbertonschool.com/holberton-logo-simple-200s.png)](https://www.holbertonschool.com)
