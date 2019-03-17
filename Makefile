#
# TODO: 
#


# $@: the target filename.
# $*: the target filename without the file extension.
# $<: the first prerequisite filename.
# $^: the filenames of all the prerequisites, separated by spaces, discard duplicates.
# $+: similar to $^, but includes duplicates.
# $?: the names of all prerequisites that are newer than the target, separated by spaces.

 
CC := g++
 # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src

BUILDDIR := build
# Main exucutable of the project
TARGET := bin/runner
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
# Compiler flags
CXXFLAGS := -g -std=c++14
# -Wall
#Libraries
LIB := -L/usr/lib/x86_64-linux-gnu/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system 
#LIB := -pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
INC := -I include


# $(TARGET): $(BUILDDIR)/driver.o
# 			@echo "Linking"
# 			@echo "$(CC) $(CFLAGS) -o $(TARGET) $(BUILDDIR)/driver.o";$(CC) $(CFLAGS) -o $(TARGET) $(BUILDDIR)/driver.o

# $(BUILDDIR)/driver.o: src/driver.cpp
# 	@mkdir -p $(BUILDDIR)
# 	@echo " $(CC) $(CFLAGS) -c -o $(BUILDDIR)/driver.o src/driver.cpp"; $(CC) $(CFLAGS) -c -o $(BUILDDIR)/driver.o src/driver.cpp

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LIB)"; $(CC) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CXXFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CXXFLAGS) $(INC) -c -o $@ $<


clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
# tester:
# 	@echo "$(SRCDIR),$(BUILDDIR) $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%, src/object.o) " #$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# # Spikes
# ticket:
#   $(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean