
# CXX = g++
# CXXCOMMONFLAGS = -std=gnu++1y -Wall -Wno-format-security -Wshadow

CXX = g++-9
WARNINGS = -Wall -Wno-format-security -Wshadow -fconcepts
BOOSTINCLIB = -I/home/y-tanabe/lib/boost_1_73_0
CXXCOMMONFLAGS = -std=gnu++17 $(WARNINGS) $(BOOSTINCLIB)

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

PROGS = cans1 cans2 cans3 cans4 cans5 cans6 cans11 cans15 cans16 \
        naive1 naive2 naive3 naive11

all: $(PROGS)

clean:
	$(RM) cans.o cans cans.exe $(PROGS) *~ *.stackdump core din_x*.txt dact_x*.txt dexp_x*.txt


