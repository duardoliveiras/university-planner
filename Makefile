# Set gcc as the C++ compiler
CXX=g++

# Enforce C++ 2011 as the language standard
CXXFLAGS=-std=c++11 -pedantic

# Enable all standard warnings, uninitialized variable warnings, 
# and treat all warnings as errors
CXXFLAGS+= -Wall -Wuninitialized -Werror

# Generate code with debugging information
# (for use with a debugger like gdb)
CXXFLAGS+= -g

# Link with math library
CXXFLAGS+= -lm

CXXFLAGS+=-fsanitize=address -fsanitize=undefined

# C++ source files to consider in compilation
CPP_FILES=main.cpp menu.cpp functions/dbClasses.cpp functions/dbOneStudent.cpp functions/dbOneUc.cpp functions/dbStudents.cpp functions/dbUcs.cpp

# C++ header files to consider in compilation
HEADERS=
# Name of executable program ('main' by default)
PROG=a.out

$(PROG): $(CPP_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(CPP_FILES) -o $(PROG)
