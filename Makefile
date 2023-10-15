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
CPP_FILES=main.cpp menu.cpp errorMsgs.cpp
CPP_FILES+=functions/dbClasses.cpp functions/dbStudents.cpp functions/dbUcs.cpp functions/requests.cpp
CPP_FILES+=inputoutput/readAllClasses.cpp inputoutput/readAllStudents.cpp inputoutput/readAllUcs.cpp inputoutput/keepAllChanges.cpp inputoutput/print.cpp 
CPP_FILES+=mgmt/filterInfo.cpp mgmt/orderInfo.cpp mgmt/selectInfo.cpp mgmt/requests.cpp

# C++ header files to consider in compilation
HEADERS=classes/class.h classes/student.h classes/uc.h

# Name of executable program ('main' by default)
PROG=a.out

$(PROG): $(CPP_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CPP_FILES) -o $(PROG)
