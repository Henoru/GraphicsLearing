VPATH=Module
SRC=$(wildcard *.cpp Module/*.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))
all:$(OBJ)
	g++ -std=c++11 -O3 $(OBJ) -o main
$(OBJ):%.o:%.cpp
	g++ -std=c++11 -c $< -o $@
.PHONY:clean
clean:
	rm $(OBJ)