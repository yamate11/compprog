#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#if defined(DEBUG)

#include <unistd.h>
#include <sys/fcntl.h>
#define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
#define DCALL(func, ...) func(__VA_ARGS__)

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#else  // defined(DEBUG)

#define DLOG(...)
#define DCALL(func, ...)

#endif // defined(DEBUG)

class FastIO {
  static const int rdata_sz = (1 << 25), wdata_sz = (1 << 25);
  char rdata[rdata_sz], wdata[wdata_sz];
  char *rb, *wb;
  char s[20];

public:
  FastIO() {
    fread(rdata, 1, rdata_sz, stdin);
    rb = rdata; wb = wdata;
  }
  ~FastIO() {
    fwrite(wdata, 1, wb - wdata, stdout);
  }

  template<typename T>
  inline void read_i(T &x) {
    bool neg = false;
    x = 0;
    while((*rb < '0' || *rb > '9') && *rb != '-') ++rb;
    if(*rb == '-') {
      neg = true; ++rb;
    }
    while('0' <= *rb && *rb <= '9') {
      x = 10 * x + (*rb - '0');
      ++rb;
    }
    if(neg) x = -x;
  }

#define pc(x) *(wb++) = x
  template<typename T>
  inline void writeln_i(T x) {
    if (x == 0) { pc('0'); pc('\n'); return;}
    if(x < 0) { pc('-'); x = -x; }
    char *t = s;
    while(x) {
      T y = x / 10;
      *(t++) = (x - y*10) + '0';
      x = y;
    }
    while(t != s) pc(*(--t));
    pc('\n');
  }
  #undef pc
};

FastIO io;
int N, Q;
set<int> A;

void myAdd(int x) {
  auto it = A.find(x);
  if (it == A.end()) A.insert(x);
  else               A.erase(it);
}

int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
#endif

  io.read_i(N); io.read_i(Q);
  for (int i = 0; i < N; i++) {
    int a; io.read_i(a);
    myAdd(a);
  }
  for (int j = 0; j < Q; j++) {
    int l, r, x; io.read_i(l); io.read_i(r); io.read_i(x);
    int ax = 0;
    int cnt = 0;
    {
      auto itB = A.lower_bound(l);
      auto it = itB;
      for ( ; it != A.end() && *it <= r; it++) {
	ax ^= *it;
	cnt++;
      }
      A.erase(itB, it);
    }
    io.writeln_i(ax);
    if (cnt % 2 == 1)  myAdd(x);
  }

  return 0;
}

