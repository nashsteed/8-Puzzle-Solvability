# Nash Steed _ ucq8hz _ Apr 28 2022 _ Makefile

# Defines the C++ compiler we'll be using
CXX = clang++
CXXFLAGS=-Wall -O2
DEBUG=-g

OBJECTS = puzzle8.o 

# Compile our files into a.out
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen


# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~