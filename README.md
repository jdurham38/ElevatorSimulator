This program complier is clang. Press shift + cmd + p to get to the command pallette and select the c/c++ cland compiler.

Then press F5 to run the code.





Compile LinkedList.cpp and create an object file:
 - clang++ -c LinkedList.cpp -o LinkedList.o


Compile main.cpp and create an object file:
 - clang++ -c main.cpp -o main.o

Link both object files together to create the executable:
 - clang++ LinkedList.o main.o -o output/main

Run the executable:
 - ./output/main