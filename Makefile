# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Executable name
TARGET = quant

# Source files
SRCS = main.cpp prepare.cpp

# Object files - derived from source files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = prepare.h

# The default target, 'all', which builds the executable
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile .cpp files into .o files.
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# A rule to clean up the build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets are not files
.PHONY: all clean
