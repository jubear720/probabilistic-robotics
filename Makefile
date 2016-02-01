# source files
SOURCES_ASM := 

SOURCES_CC  := src/map.cc src/sensormodel.cc

# object files
OBJS        := $(patsubst %.S,%.o,$(SOURCES_ASM))
OBJS        += $(patsubst %.cc,%.o,$(SOURCES_CC))

# Build flags
INCLUDES    := -I.
ASFLAGS     := 
CFLAGS      := -Wall -g $(INCLUDES)
LFLAGS	    := -g
LIBS        := -lpng

# build targets 
testsensormodel: src/testsensormodel.o $(OBJS)
	g++ $(LFLAGS) -o $@ src/testsensormodel.o $(OBJS) $(LIBDIRS) $(LIBS)


# Compile CC to object file
%.o: %.cc
	g++ $(CFLAGS) -c $< -o $@

# Compile Assembly to object file
%.o: %.S
	g++ $(ASFLAGS) -c $< -o $@

# Clean up the build directory
clean:
	rm -rf *.o 

dist-clean: clean
	rm -f ../doc/range-sensor/*.aux ../doc/range-sensor/*.bak ../doc/range-sensor/*.log ../doc/range-sensor/*~
	rm -rf *~
	rm -f testsensormodel
	rm -f pgm/*.pgm

