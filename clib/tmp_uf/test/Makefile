### If you want to build with debug options, invoke make as:
###     make DEBUG=yes

CXX := g++

ifneq ($(DEBUG),yes)
  DEBUGFLAGS := -O2
else
  DEBUGFLAGS := -g -O0 -D_GLIBCXX_DEBUG -DDEBUG=1
  ifneq ($(DEBUG_LIB),)
    DEBUGFLAGS := $(DEBUGFLAGS) -DDEBUG_LIB=1
  endif
endif

WARNINGS := -Wall -Wno-format-security -Wshadow -fconcepts

CXXFLAGS := -std=gnu++20 $(DEBUGFLAGS) $(WARNINGS)

CXXFLAGS := $(CXXFLAGS) -I/home/y-tanabe/lib/boost_1_73_0
CXXFLAGS := $(CXXFLAGS) -I/home/y-tanabe/proj/compprog/clib/ac-library
CXXFLAGS := $(CXXFLAGS) $(if $(CMPNAIVE),-DCMPNAIVE=1)
CXXFLAGS := $(CXXFLAGS)

skels := $(wildcard *_skel.cc)
ts := $(patsubst %_skel.cc,%_t.cc,$(skels))
pars := $(patsubst %_skel.cc,../%.cc,$(skels))
makefiles := $(patsubst %_skel.cc,%_t.d,$(skels))
execsSub := $(patsubst %_skel.cc,%_t,$(skels))
execs := $(execsSub) convolutionS_t

.PHONY: all test

all: $(execs)

test: all
	./clib_test $(execs)

include $(makefiles)

%_t.cc %_t.d &: %_skel.cc
	libins --clib-dir .. -M -o $*_t.cc -i $*_skel.cc --orig-lineno

%: %.cc
	$(CXX) -o $@ $(CXXFLAGS) $<

convolutionS_t: convolution_t.cc
	$(CXX) -o convolutionS_t $(CXXFLAGS) -DTEST_CONSTANT_MOD=1 convolution_t.cc


# If you need intermediate %_.cc files, uncomment the following line.
# .PRECIOUS:  %_t.cc

clean:
	$(RM) $(ts) $(execs) $(makefiles) *~ \#*

check:
	echo $(execs)
