CXX = g++
CXXFLAGS = -std=c++1y -pedantic -Wall -Werror
LDFLAGS = -shared
BUILD = program
SRC = engine.cc motor_vehicle.cc two_wheel_vehicle.cc motorcycle.cc
OBJ = $(SRC:.c=.o)

$(BUILD): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $@ $^ main.cc

clean:
		rm -rf $(BUILD) *.o
