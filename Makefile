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
CPP_FILES+=functions/dbClasses.cpp functions/dbStudents.cpp functions/dbUcs.cpp functions/requests.cpp
CPP_FILES+=output/printClass.cpp output/printStudent.cpp output/printUc.cpp 
CPP_FILES+=menu/menuGroup.cpp menu/menuInfo.cpp menu/menuOrder.cpp menu/menuPrincipal.cpp  menu/menuRequests.cpp menu/menuSelectInfo.cpp menu/menuSub.cpp
CPP_FILES+=input/readAllClasses.cpp input/readAllStudents.cpp input/readAllUcs.cpp input/keepAllChanges.cpp
CPP_FILES+=debug/errorMessages.cpp debug/workingMessage.cpp
CPP_FILES+=mgmt/filterInfoClass.cpp mgmt/filterInfoStudent.cpp mgmt/filterInfoUc.cpp 
CPP_FILES+=mgmt/orderInfoClass.cpp mgmt/orderInfoStudent.cpp mgmt/orderInfoUc.cpp
CPP_FILES+=mgmt/selectClass.cpp mgmt/selectStudent.cpp mgmt/selectUc.cpp
CPP_FILES+=requests/addClass.cpp requests/removeClass.cpp requests/switchClass.cpp

# C++ header files to consider in compilation
HEADERS=classes/class.h classes/student.h classes/uc.h

# Name of executable program ('main' by default)
PROG=a.out

$(PROG): $(CPP_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CPP_FILES) -o $(PROG)
