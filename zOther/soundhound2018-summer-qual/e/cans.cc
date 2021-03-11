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
// ----------------------------------------------------------------------

template<typename F>
class FixPoint : private F {
public:
  explicit constexpr FixPoint(F&& f) noexcept : F(forward<F>(f)) {}

  template<typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template<typename F>
static inline constexpr decltype(auto) fix(F&& f) noexcept {
  return FixPoint<F>{forward<F>(f)};
}

// ----------------------------------------------------------------------
struct MyException: exception {};

struct Peer {
  int nd;
  int wt;
  Peer(int n, int w) : nd(n), wt(w) {}
};

struct Crt {
  int cst;
  char sgn;
  Crt(int c, int s) : cst(c), sgn(s) {}
};

int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cout << setprecision(20);

  int N, M; cin >> N >> M;
  vector<vector<Peer>> nbr(N);
  
  for (int i = 0; i < M; i++) {
    int u, v, s; cin >> u >> v >> s; u--; v--;
    nbr.at(u).emplace_back(v, s);
    nbr.at(v).emplace_back(u, s);
  }

  int vMin = 1;
  int vMax = INT_MAX;

  vector<Crt> crt(N, Crt(0, 0));

  auto dfs = fix([&](auto f, int n, int p, int w) -> void {
      if (n == 0 && p == -1) {
	crt.at(0) = Crt(0, 1);
      }else {
	int c = w - crt.at(p).cst;
	int s = -crt.at(p).sgn;
	if (crt.at(n).sgn == s) {
	  if (crt.at(n).cst != c) throw MyException();
	  return;
	}
	if (crt.at(n).sgn == -s) {
	  int c2 = s * (crt.at(n).cst - c);
	  if (c2 % 2 == 1 || c2 / 2 < vMin || vMax < c2 / 2) {
	    throw MyException();
	  }
	  vMin = vMax = c2 / 2;
	  return;
	}
	assert(crt.at(n).sgn == 0);
	crt.at(n) = Crt(c, s);
	if (s == 1) {
	  vMin = max(vMin, 1 - c);
	}else if (s == -1) {
	  vMax = min(vMax, c - 1);
	}else {
	  assert(false);
	}
	if (vMin > vMax) throw MyException();
      }
      for (auto e : nbr.at(n)) {
	if (e.nd == p) continue;
	f(e.nd, n, e.wt);
      }
    });

  try {
    dfs(0, -1, -1);
    cout << vMax - vMin + 1 << endl;
  }catch(const MyException& e) {
    cout << 0 << endl;
  }

  return 0;
}

