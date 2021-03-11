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

typedef pair<int, double> Pair;

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
  vector<vector<Pair>> p(M);
  vector<double>cost(M);
  for (int i = 0; i < M; i++) {
    int c;
    cin >> c >> cost.at(i);
    for (int j = 0; j < c; j++) {
      int x, y; cin >> x >> y; x--;
      p.at(i).emplace_back(x, (double)y / 100.0);
    }
  }
  vector<double> memo(1<<N, -1);
  memo.at((1<<N)-1) = 0;

  /*
    e = p0(1+e) + p1(1+e1) + ... + pk(1+ek)
      = 1 + p0e + p1e1 + ... + pkek
    e = 1/(1-p0) * [ 1 + p1e1 + ... + pkek ]
   */

  auto getExp = fix([&](auto f, int t) -> double {
      if (memo.at(t) >= 0) return memo.at(t);
      double rv = DBL_MAX;
      for (int i = 0; i < M; i++) {
	double pLoop = 0.0;
	double eSum = cost.at(i);
	for (Pair w : p.at(i)) {
	  int person = w.first;
	  double prob = w.second;
	  int bit = 1 << person;
	  if (t & bit) {
	    pLoop += prob;
	  }else {
	    eSum += prob * f(t | bit);
	  }
	}
	double thisCost = abs(1.0 - pLoop) < 1e-6 ?
					     DBL_MAX : eSum/(1.0 - pLoop);
	rv = min(rv, thisCost);
      }
      memo.at(t) = rv;
      return rv;
    });

  double x = getExp(0);
  cout << x << endl;
  return 0;
}

