# Leave
A program that tries to do the opposite of the rm Unix command: removes all files in the current directory except the specified one, and executable and source code.

Writing this program was small but fun; I'm glad I was curious.
It involves library system calls and file I/O. 

Challenges were found in understanding and reviewing C strings and method use, such as arrays, char pointers, strcat, strcpy, and fgets. Remembering string literals are in the code segment -> NOT to be written to!
This is a good program to try building if you want to review these things. 
-> But, make sure you test in a new folder. Don't want you to be accidently removing all your files!

Example:<br>
% ls
a.txt b.txt c.txt leave.c leave
% ./leave a.txt
% ls
a.txt leave.c leave
