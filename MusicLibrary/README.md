## CS 474 - Music Library
### Guglielmo Menchetti

#### Installation

This project has been tested on a GNU C++11 compiler, using the editor CLion. the compiler to c++11.

#### Features

A user of the MLS can apply the following commands:

- l : list all the available files
- e : set the current clip as the ID provided by the user (between 0-9)
- c : create a new clip with the information provided by the user
- y : copy the current clip into a temporary file named "temp.clip"
- i : execute the commands from the file "input.inp"
- p : update the price for the current clip
- s : save all the clips in memory in files (contained in the folder clips)
- q : quit

#### Notes

For the __create new clip__ and __read from file__ functionalities the input data are assumed to be 
correct. Furthermore, __read from file__ reads from "input.inp" that must be formatted in the following
way
```
l
e 4
p 3.41
c 4 3222 J_Lo Martin,Frank_Sinatra This_is_the_word 3 3.15
y 
s
e 2
p 1.24
s
```
The function _c_ take the following list as input:
- ID 
- Index 
- Artist name (space replaced by _)
- Group components name (_ if none)
- Song title (space replaced by _)
- Genre (a value between 0-9)
- Price (a floating value)
