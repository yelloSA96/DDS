makefile: 

all: main InputandOutput


main: main.cpp
    g++ -c -g main.cpp

InputandOutput: InputandOutput.h InputandOutput.cpp
    g++ -c InputandOutput.cpp 
    
    
    
clean:
    -rm main InputandOutput