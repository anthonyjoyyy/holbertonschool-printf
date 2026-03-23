# _printf

# a printf clone

## prototype:  
	_printf(const char *, ...);

## syntax:
	_printf("<SPECIFIER>[FLAGS][WIDHT][PERSISION]<FORMAT>", <DATA>);
	SPECIFIER - % tells _printf to print extra data
	FLAGS - {'0','-','+',' '} extra formating to aply
	WIDTH - {number} minmum space to take
	PERSISON - {'.' followed by number} what persion to use (number after . for floats, number of minumum digits for int, max charcter for string)
	FORMAT - character repisenting what type the data will be
	DATA - the data to print, string, character, int, variable

## compilation & usage:  
	git clone URL
	place your main.c file in the dowloaded folder
	add `#include "main.h"` to the begining your main.c file
	compile with the following command:
	`gcc @info/flags -Wno-format *.c main.c`

## exapmles:
	to print basic string:
		`_printf("HELLO WORLD\n");`
		Output: HELLO WORLD

	to print a string from a variable use %s:
		```
		char *str = "WORLD";
		_printf("HELLO %s\n", str);
		```
		Output: HELLO WORLD
	
	to print a number use %d:
		`_printf("Meaning Of Life: %d", 42);`
		Output: Meaning Of Life: 42
	
### AUTHORS:
####	SEBASTION. P & ANTHONY. J

# TODO:
- [X] add comments
- [X] free all strings
- [X] add * for width
- [X] stuct intead of switch
- [X] variable naming
- [ ] function breakdown and seporation
- [X] update test description
- [X] update componets list
- [ ] update readme for secription
