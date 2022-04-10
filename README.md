MAN PAGE.

Not interactive mode
It executes the shell, first argument after itself will be taken as first argument by simple shell, ending the process afterwards.

Example: ./simple_shell pwd
it will display current working directory in stdout and terminate the program afterwards.

Interactive mode</h3>

Interactive mode will set a loop reading from stdin, the shell can be used with several arguments, several times, untill exiting signal is entered.


<h3>Arguments</h3>
Simple_shell takes arguments separated by spaces from the command line. It works by tokenizing the input from stdin. Input from stdin is a string ending in '\n' before terminating byte '\0'.

The tokens are stored into a list, first string in the list will be searched in existing PATH directories (see <b>env</b> for PATH directories) if found it will recognize it as a command and execute the program. Following arguments will be taken as flags for the requested program.

If no match is found for any valid PATH, it will not recognize it as a command and will prompt ":command not found" message.


<h3>Exit the shell</h3>
Te exit the shell it needs to receive one of the following arguments:
<b>EOF
end-of-file
(Ctrl + d)
exit</b>
Internally it sends a return value of (-1) wich terminates the line receiving loop thus terminating the process.

