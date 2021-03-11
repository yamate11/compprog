CXX = g++-9
CXXCOMMONFLAGS = -std=gnu++17 -Wall -Wno-format-security -Wshadow -fconcepts
# CXXCOMMONFLAGS = -std=gnu++1y -Wall -Wno-format-security -Wshadow
BOOSTINCLIB = -I/opt/boost/gcc/include -L/opt/boost/gcc/lib
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


# CXXFLAGS = -O2 $(CXXCOMMONFLAGS) $(BOOSTINCLIB)

all: cans

clean:
	$(RM) cans.o cans cans.exe *~ *.stackdump core

