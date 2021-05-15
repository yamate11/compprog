
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

ifeq ($(USE_CONSTANT_MOD),)
else
CXXFLAGS := $(CXXFLAGS) -DUSE_CONSTANT_MOD
endif

EXEC := cans mod_t foo

all: $(EXEC)

clean:
	$(RM) $(EXEC) cans.o cans.exe *~ *.stackdump core

