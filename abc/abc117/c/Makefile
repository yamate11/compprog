CXXCOMMONFLAGS = -std=gnu++1y -Wall -Wno-format-security -Wshadow
BOOSTINCLIB = -I/opt/boost/gcc/include -L/opt/boost/gcc/lib
ifdef DEBUG
  CXXFLAGS = -g -O0 $(CXXCOMMONFLAGS) -DDEBUG=$(DEBUG)
else
  CXXFLAGS = -O2 $(CXXCOMMONFLAGS)
endif
# CXXFLAGS = -O2 $(CXXCOMMONFLAGS) $(BOOSTINCLIB)

all: cans

clean:
	$(RM) cans.o cans cans.exe *~ *.stackdump core

