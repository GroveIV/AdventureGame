CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS = -Wall
CXXFLAGS = -pedantic-errors
CXXFLAGS = -g

SRC1 = abstractRoom.cpp bedroom.cpp buildRoom.cpp game.cpp input.cpp inventory.cpp main.cpp menu.cpp movieRoom.cpp senseRoom.cpp subRoom.cpp

HEADER = abstractRoom.hpp bedroom.hpp buildRoom.hpp game.hpp input.hpp inventory.hpp menu.hpp movieRoom.hpp senseRoom.hpp spaces.hpp subRoom.hpp

finalProject: ${SRC1}  ${Header}
	${CXX} ${CXXFLAGS}  ${SRC1}  -o main 

clean:
	 rm -f main
