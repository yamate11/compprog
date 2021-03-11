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
struct MyException : exception {};

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

  int N; cin >> N;
  vector<int> A(N-1), B(N-1);
  vector<vector<int>> nbr(N);

  for (int i = 0; i < N-1; i++) {
    int a, b; cin >> a >> b;
    A.at(i) = a;
    B.at(i) = b;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }

  auto branch = [&](int nd) -> int {
    auto nxt = [&](int& node, int& source) -> void {
      for (int x : nbr.at(node)) {
	if (x != source) {
	  source = node;
	  node = x;
	  return;
	}
      }
      throw MyException();
    };
    int src = -1;
    while (nbr.at(nd).size() <= 2) nxt(nd, src);
    return nd;
  };

  vector<int> brnum(N);
  int ans = 0;
  try {
    for (int i = 0; i < N; i++) {
      if (nbr.at(i).size() > 1) continue;
      int j = branch(i);
      brnum.at(j)++;
    }
    for (int i = 0; i < N; i++) {
      if (brnum.at(i) >= 2) ans += brnum.at(i) - 1;
    }
  } catch(const MyException& e) {
    ans = 1;
  }
  cout << ans << endl;

  return 0;
}

