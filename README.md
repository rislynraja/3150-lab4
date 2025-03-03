# 3150-lab4

instructions:

- make sure all necessary c/c++ extensions are installed run this line in the terminal in order to run the tests and compile the files: 
g++ -std=c++17 -Iinclude -o testlinkedlist LinkedList.cpp nodeUnitTests.cpp
- in order to view results run the following line in the terminal: 
./testlinkedlist

notes:

- files included:
    - doctest.h - testing file (given)
    - Node.h - definition for node struct
    - LinkedList.h - definition for class linked list and list of functions
    - LinkedList.cpp - implementation for the functions listed in LinkedList.h