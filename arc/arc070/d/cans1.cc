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

  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++)  cin >> A.at(i);
  sort(A.begin(), A.end());

  auto chk = [&](int i) -> bool {
    if (A.at(i) >= K) return true;
    vector<bool> tbl(K);
    tbl.at(0) = true;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      int a = A.at(j);
      for (int x = K-1; x-a >= 0; x--) {
	if (tbl.at(x-a)) {
	  if (K <= x + A.at(i)) return true;
	  tbl.at(x) = true;
	}
      }
    }
    return false;
  };
  
  auto bsch = fix([&](auto f, int lo, int hi) -> int {
      if (lo + 1 == hi)  return hi;
      int mid = (lo + hi) / 2;
      if (chk(mid)) return f(lo, mid);
      else          return f(mid, hi);
    });

  int i0 = bsch(-1, N);
  cout << i0 << endl;

  return 0;
}

