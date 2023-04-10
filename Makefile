CXXFLAGS=-Wall -Werror --std=c++17

all:
	c++ -o my_string *.cpp $(CXXFLAGS)