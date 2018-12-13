#
# TODO: 
#
 
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
CFLAGS := -g -std=c++11 # -Wall
#Libraries
LIB := -pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
INC := -I include


$(TARGET): $(BUILDDIR)/driver.o
			@echo "Linking"
			@echo "$(CC) $(CFLAGS) -o $(TARGET) $(BUILDDIR)/driver.o";$(CC) $(CFLAGS) -o $(TARGET) $(BUILDDIR)/driver.o

$(BUILDDIR)/driver.o: src/driver.cpp
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) -c -o $(BUILDDIR)/driver.o src/driver.cpp"; $(CC) $(CFLAGS) -c -o $(BUILDDIR)/driver.o src/driver.cpp

# $(TARGET): $(OBJECTS)
#   @echo " Linking..."
#   @echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

#$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
#  @mkdir -p $(BUILDDIR)
#  @echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<


clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# # Tests
# tester:
#   $(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# # Spikes
# ticket:
#   $(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean