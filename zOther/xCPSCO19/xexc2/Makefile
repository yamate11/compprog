CXXCOMMONFLAGS = -std=gnu++1y -Wall -Wno-format-security
BOOSTINCLIB = -I/opt/boost/gcc/include -L/opt/boost/gcc/lib
CXXFLAGS = -O2 $(CXXCOMMONFLAGS)
# CXXFLAGS = -O2 $(CXXCOMMONFLAGS) $(BOOSTINCLIB)

all: cans

debug:
	$(CXX) -g $(CXXCOMMONFLAGS) -DDEBUG=1 -o cans cans.cc

clean:
	$(RM) cans.o cans.exe *~ *.stackdump core

