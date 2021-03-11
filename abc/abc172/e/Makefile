
# CXX = g++
# CXXCOMMONFLAGS = -std=gnu++1y -Wall -Wno-format-security -Wshadow

CXX = g++-9
WARNINGS = -Wall -Wno-format-security -Wshadow -fconcepts
BOOSTINCLIB = -I/home/y-tanabe/lib/boost_1_73_0
CXXCOMMONFLAGS = -std=gnu++17 $(WARNINGS) $(BOOSTINCLIB)

ifdef CMPNAIVE
  CMPNAIVEFLAG = -DCMPNAIVE=1
else
  CMPNAIVEFLAG = 
endif

ifdef DEBUG
  CXXFLAGS = -g -O0 $(CXXCOMMONFLAGS) $(CMPNAIVEFLAG) -DDEBUG=1
else
  CXXFLAGS = -O2 $(CXXCOMMONFLAGS) $(CMPNAIVEFLAG)
endif

all: cans

clean:
	$(RM) cans.o cans cans.exe *~ *.stackdump core

