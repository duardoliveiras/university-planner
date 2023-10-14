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
CPP_FILES=main.cpp menu.cpp 
CPP_FILES+=functions/dbClasses.cpp functions/dbStudents.cpp functions/dbUcs.cpp 
CPP_FILES+=output/printClass.cpp output/printStudent.cpp output/printUc.cpp 
CPP_FILES+=menu/menuGroup.cpp menu/menuInfo.cpp menu/menuOrder.cpp menu/menuPrincipal.cpp menu/menuSub.cpp
CPP_FILES+=readDB/readAllClasses.cpp readDB/readAllStudents.cpp readDB/readAllUcs.cpp
CPP_FILES+=debug/checkError.cpp debug/errorMessage.cpp
# C++ header files to consider in compilation
HEADERS=
# Name of executable program ('main' by default)
PROG=a.out

$(PROG): $(CPP_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(CPP_FILES) -o $(PROG)
