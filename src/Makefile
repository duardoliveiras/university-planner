# Set gcc as the C++ compiler
CXX=g++

# Enforce C++ 2011 as the language standard
CXXFLAGS=-std=c++17 -pedantic

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
CPP_FILES=main.cpp menu.cpp errorMsgs.cpp
CPP_FILES+=functions/dbStudents.cpp functions/dbUcs.cpp 
CPP_FILES+=inputoutput/read.cpp inputoutput/print.cpp inputoutput/keepAllChanges.cpp
CPP_FILES+=classes/student.cpp classes/uc.cpp 

# C++ header files to consider in compilation
HEADERS=menu.h
HEADERS+=functions/dbStudents.h functions/dbUcs.h
HEADERS+=inputoutput/print.h inputoutput/read.h inputoutput/keepAllChanges.h
HEADERS+=classes/student.h classes/uc.h

# Name of executable program ('main' by default)
PROG=a.out

$(PROG): $(CPP_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CPP_FILES) -o $(PROG)
