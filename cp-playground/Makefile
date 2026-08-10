# Compiler to use
CXX = g++

# Compiler flags
# -std=c++17 : Compile using the C++17 standard
# -Wall      : Enable common compiler warnings
CXXFLAGS = -std=c++17 -Wall

# Name of the executable to create
TARGET = solution

# Default target: runs when you simply type `make`
all: $(TARGET)
	./$(TARGET)

# Compile solution.cpp into the executable
$(TARGET): solution.cpp
	$(CXX) $(CXXFLAGS) solution.cpp -o $(TARGET)

# Remove the compiled executable
clean:
	rm -f $(TARGET)