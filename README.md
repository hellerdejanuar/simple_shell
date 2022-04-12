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
     /_printf.c
          Main file.
     /fn_sel.c
          Function pointer to identified module functions.
     /fn_unk.c
          Counter function for an unknown identifier.
     /fn_print.c
          Definition of functions for character, string and module.
     /_print_i.c
          Definition of function for integers and decimals.
     /_print_ui.c
          Definition of function for unsigned integers.
     /_pwr.c
          Function to raise x to the power of x.
     /_putchar.c
          Custom function of putchar() to print the chars of the string.

###### BUGS
     Incomplete.

###### AUTHOR
     Florencia Mestre and German Izquierdo<https://github.com/FloLys/simple_shell>
