# Compiler to use
CXX = g++

# Compiler flags
# -std=c++17 : Compile using the C++17 standard
# -Wall      : Enable common compiler warnings
CXXFLAGS = -std=c++17 -Wall

# Name of the executable to create
TARGET = IntroductoryProblems

# Default target: runs when you simply type `make`
all: $(TARGET)
	./$(TARGET)

# Compile IntroductoryProblems.cpp into the executable
$(TARGET): IntroductoryProblems.cpp
	$(CXX) $(CXXFLAGS) IntroductoryProblems.cpp -o $(TARGET)

# Remove the compiled executable
clean:
	rm -f $(TARGET)