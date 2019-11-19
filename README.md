# Description
 
This folder contains two projects developed in C++ for Object Oriented Languages and Environments class during Fall 2018.
The projects are:
- **Music Library Service**: implementation of the back-end of a Music Service Library
- **Programmable Calculator**: calculator that lets users specify sequences of arithmetic operations on 4 registers

## Music Library Service (MLS) description
The service maintains a set of audio files containing a large number of songs and it will deliver a music file upon demand from a service user. The MLS is not responsible for playing music segments and interfacing to service users; this functionality is implemented in the MLS’s front-end, which is not part of this project. However, the back-end is responsible for maintaining the audio clips, including add and removing clips, editing existing clisps and duplicating audio clips (for the purpose of delivering songs to MLS users).

The user can execute the following commands:
- l: List all music clips
- e: Edit a music clip
- c: Create a music clip
- y: Copy the current clip
- i: Read commands from file
- p: Changes the price of the current music clip
- s: Save all clips
- q: Quits the MLS

#### Note
This test version of the MLS back-end contains just 10 MusicClip instances and the corresponding smart pointers. The index of these instances ranges from 0 to 9. Each of the ten instances is stored in a separate file (in the *clips* folder).

## Programmable Calculator
The PC allows the user to execute arithmetic expression conforms to the following four patterns, where id can be one of x, y, w and z and op can be one of +, -, *, ** and /:
1. id = id op id.
2. id = id op constant. 
3. id = constant.
4. id ? go int.
Expression execution ends when the last expression in the sequence has been evaluated. However, to prevent infinite execution loops, expression execution is halted also after 100 expressions have been evaluated.

The user can execute the following commands:
- i <file name>: This command reads an input file containing an instruction sequence.
- d: Execute one instruction and display both the content of the the 4 registers and the index position of the next instruction to be executed
- r: Execute the instruction sequence from the index position of the next instruction to be executed until the completion of the instruction sequence or the limit of 100 instructions is reached
- c: This command continues the execution of the program for an additiona 100 instructions
- p: This command prints the instruction sequence (with line numbers) and the content of the registers on the user’s console (i.e., the standard output stream)
- q: This exits the PC
