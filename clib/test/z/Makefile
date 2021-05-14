
# CXX = g++
# CXXCOMMONFLAGS = -std=gnu++1y -Wall -Wno-format-security -Wshadow

CXX = g++-9
WARNINGS = -Wall -Wno-format-security -Wshadow -fconcepts
BOOSTINCLIB = -I/home/y-tanabe/lib/boost_1_73_0
ATCODERLIB = -I/home/y-tanabe/proj/compprog/clib/ac-library
CXXCOMMONFLAGS = -std=gnu++17 $(WARNINGS) $(BOOSTINCLIB) $(ATCODERLIB)

ifdef CMPNAIVE
  CMPNAIVEFLAGS = -DCMPNAIVE=1
else
  CMPNAIVEFLAGS = 
endif

ifdef DEBUG
  DEBUGFLAGS = -g -O0 -D_GLIBCXX_DEBUG -DDEBUG=1
else
  DEBUGFLAGS = -O2
endif

ifeq ($(DEBUG), 2)
  DEBUGFLAGS = -g -O0 -D_GLIBCXX_DEBUG -DDEBUG=1 -DDEBUG_LIB=1
endif

CXXFLAGS = $(DEBUGFLAGS) $(CMPNAIVEFLAGS) $(CXXCOMMONFLAGS) 

all: polynomial_t

clean:
	$(RM) cans.o cans cans.exe *~ *.stackdump core

