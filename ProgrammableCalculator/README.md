##CS 474 - Project 3
###Guglielmo Menchetti

####Installation

This project has been tested on a GNU C++11 compiler, using the editor CLion.

####Features

A user of the Programmable Calculator can apply the following commands:

- i <filename>: read the input file <filename> containing an instruction sequence
- d: execute the program in debug mode (one instruction at a time)
- r: execute all the instructions (with a limit of 100 instructions for each run)
- c: if the program is not terminated, execute other 100 instructions
- p: print the instruction sequence and the content of the registers
- q : quit the PC

####Notes

The file to be loaded for the program should be a ".txt" file in the "InstructionFiles" directory.

Each instruction must contain a "." at the end.

An example of a valid instruction sequence is the following:
```
x = y ** z.
z = 5.
y = y + 3.2.
w = w - 2.2.
z = z - 1.
z ? 4.
```

