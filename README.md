![Shell](https://pandorafms.com/blog/wp-content/uploads/2020/04/sistema-operativo-de-servidor-featured.jpg)
# Simple_Shell
**By Mauricio Heller and Agustín Labadie, for Holberton School**
Holberton School, c17 - April 2022

# Introduction
Simple_Shell is a simplified version of the **shell**, built by our team from the ground up. 

The **Shell** is the  the main interface used in UNIX-like systems, 
It is usually used to manage files, navigate the filesystem and execute programs via the command line without interacting directly with the OS.


# Features 
Our **simple_shell** mimics the behaviour of the original shell, displaying a prompt and waiting for the user to input commands, which usually consist of a program name to execute and the desired flags and arguments needed for it to work.

It also includes built-in commands to expand the capabilities of the **simple_shell** beyond that of the programs installed.

The current version of **simple_shell** does not feature filesystem navigation yet, but it allows the user to use linux file management tools such as *rm* , *mkdir* , etc.


# How to use it

After running the program the user is presented with a prompt reading '$ ' and the interface waits for the user to input some commands.
The command is divided in tokens separated by spaces, each token serves a different purpose.
The first token is for the name of the program, the options here are:
      Writing the name of an installed program (ls), present in some of directories defined in the PATH environment variable.
      Specifying the full path of an excutable located in any directory of the system, startign with a '/'
      Typing one of the built in commands
      
Press enter to search for the program and try to run it.      
If the name token doesnt meet any of condition cited above, it will print a "not found" error.
(when no text is typed it will print a new prompt with no message and wait for input, as if nothing happened)



To exit the **simple_shell** you can terminate it with `Ctrl+C` like any other program.

Alternatively, the built-in exit methods are: 
      Pressing `Ctrl+D`
      Typing `exit`, `EOF`, `end-of-file`
      
After using any of these methods, it will print exit and terminate.      

##### BUILT-INS

    env   Prints the local environmental variables
     
    exit  closes the simple_shell

##### FILES
     /simple_shell.c
          Main file.
     /_getline_tok.c
          Function that tokenizes input from stdin. Returns an index.
     /_getenv.c
            Searches for a value in the local environment variables.
     /_list_cntr.c
            Counts elements of a list or index.
     /_strcmp.c
            Compares two strings, Returns 1 if success.
     /_strconcat.c
            Concatenates two strings, adds '\0' at end.
     /_strlen.c
            Function that returns the length of a string.
     /_strncmp.c
            Compares two strings character by character, from beggining @n times.
     /_tokcntr.c
            Counts tokens in a string parsed by *token.
     /_token_to_av.c
            Makes list from string by tokenizeing throug a separator.
     /main.h
            Header.

###### BUGS
Simple_shell does not support moving cursor with arrows.

###### AUTHOR
Agustin Labadie <labalabadie@gmail.com>
Mauricio Heller <hellerdejanuar@gmail.com>
