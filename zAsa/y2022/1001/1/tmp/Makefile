
CXX := g++

ifeq ($(DEBUG),)
  DEBUGFLAGS := -O2
else
  DEBUGFLAGS := -g -O0 -D_GLIBCXX_DEBUG -DDEBUG=1
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

all: foo

clean:
	$(RM) cans.o cans cans.exe *~ *.stackdump core foo.exe foo.o foo

foo: foo.o bar.o
	g++ -o foo foo.o bar.o
