EXES = LinTr UnionFind binsearch bit board cht cmpNaive coordCompr \
       cumsum2d debug dijkstra dinic doubling fft fix ftwo geometry \
       guessPoly ipoint intervalSet matrix minCostFlow misc mod \
       perm rerror rollingHash scc segTree sieve strSearch \
       suffixArray tree trie util interactive

CXX = g++-9
CXXCOMMONFLAGS = -std=gnu++17 -Wall -Wno-format-security -Wshadow -fconcepts -DCMPNAIVE
# CXXCOMMONFLAGS = -std=gnu++1y -Wall -Wno-format-security -Wshadow
ifdef DEBUG
  CXXFLAGS = -g -O0 $(CXXCOMMONFLAGS) -DDEBUG=$(DEBUG)
else
  CXXFLAGS = -O2 $(CXXCOMMONFLAGS)
endif

all: $(EXES)

test: $(EXES)
	./clib_test $(EXES)

clean:
	$(RM) *~ $(EXES)

