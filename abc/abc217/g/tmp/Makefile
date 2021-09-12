
CXX := g++

ifeq ($(DEBUG),)
  DEBUGFLAGS := -O2
else
  DEBUGFLAGS := -g -O0 -D_GLIBCXX_DEBUG 
  ifneq ($(DEBUG_LIB),)
    DEBUGFLAGS := $(DEBUGFLAGS) -DDEBUG_LIB=1
  endif
endif

WARNINGS := -Wall -Wno-format-security -Wshadow -fconcepts

CXXFLAGS := -std=gnu++17 $(DEBUGFLAGS) $(WARNINGS)

CXXFLAGS := $(CXXFLAGS) -I/home/y-tanabe/lib/boost_1_73_0
CXXFLAGS := $(CXXFLAGS) -I/home/y-tanabe/proj/compprog/clib/ac-library
CXXFLAGS := $(CXXFLAGS) $(if $(CMPNAIVE),-DCMPNAIVE=1)
CXXFLAGS := $(CXXFLAGS)

all: nasuo

clean:
	$(RM) nasuo.o nasuo cans.o cans cans.exe *~ *.stackdump core

