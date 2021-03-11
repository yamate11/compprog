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
  vector<vector<int>> nbr(N);
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b; a--; b--;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }
  int Q; cin >> Q;
  vector<int> V(Q), D(Q), C(Q);
  for (int i = 0; i < Q; i++) {
    int v, d, c; cin >> v >> d >> c; v--;
    V.at(i) = v;
    D.at(i) = d;
    C.at(i) = c;
  }
  vector<int> rad(N, -1), col(N);
  for (int i = Q-1; i >= 0; i--) {
    auto paint = fix([&](auto recF, int v, int d) -> void {
	if (rad.at(v) >= d) return;
	rad.at(v) = d;
	if (col.at(v) == 0) col.at(v) = C.at(i);
	if (d == 0) return;
	for (int w : nbr.at(v)) recF(w, d-1);
      });
    paint(V.at(i), D.at(i));
  }
  for (int i = 0; i < N; i++) {
    cout << col.at(i) << "\n";
  }

  return 0;
}

