EXES = UnionFind binsearch bit board cht cmpNaive coordCompr \
       cumsum2d debug dijkstra dinic doubling fix ftwo geometry \
       guessPoly ipoint intervalSet matrix minCostFlow misc mod \
       perm rerror rollingHash scc segTree dynSegTree sieve strSearch \
       suffixArray tree trie util interactive polynomial sortedIndex \
       forall mapget mypair digit topord cycledetect rbst

CXX = g++
CXXCOMMONFLAGS = -std=gnu++20 -Wall -Wno-format-security -Wshadow -fconcepts -DCMPNAIVE
# CXXCOMMONFLAGS = -std=gnu++1y -Wall -Wno-format-security -Wshadow
ifdef DEBUG
  CXXFLAGS = -g -O0 $(CXXCOMMONFLAGS) -DDEBUG=$(DEBUG)
else
  CXXFLAGS = -O2 $(CXXCOMMONFLAGS)
endif

.PHONY: test clean

all:
	@echo "You do not need to make here.  But you can do 'make test'".

test: 
	$(MAKE) -C test test

clean:
	$(RM) *~ $(EXES)

