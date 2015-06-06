CXX = g++
CXXFLAGS = -std=c++1y -pedantic -Wall -Werror
LDFLAGS = -shared
BUILD = program
SRC = 
OBJ = $(SRC:.c=.o)

$(BUILD): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $@ $^ main.cc

clean:
		rm -rf $(BUILD) *.o
