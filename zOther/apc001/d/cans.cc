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
  vector<ll> A(N);
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<vector<int>> nbr(N);
  for (int i = 0; i < M; i++) {
    cin >> X.at(i) >> Y.at(i);
    nbr.at(X.at(i)).push_back(Y.at(i));
    nbr.at(Y.at(i)).push_back(X.at(i));
  }
  vector<bool> visited(N);

  auto dfs = fix([&](auto f, int nd, int pa, auto& costs) -> void {
      if (visited.at(nd)) return;
      visited.at(nd) = true;
      costs.push_back(A.at(nd));
      for (int j : nbr.at(nd)) {
	if (j == pa) continue;
	f(j, nd, costs);
      }
    });

  vector<ll> mins;
  vector<ll> sndCosts;
  for (int i = 0; i < N; i++) {
    if (visited.at(i)) continue;
    vector<ll> costs;
    dfs(i, -1, costs);
    ll tMin = LLONG_MAX;
    for (ll c : costs) tMin = min(tMin, c);
    mins.push_back(tMin);
    bool hit = false;
    for (ll c : costs) {
      if (!hit && c == tMin) {
	hit = true;
      }else {
	sndCosts.push_back(c);
      }
    }
  }
  int k = mins.size();
  if (2*(k-1) > N) {
    cout << "Impossible\n";
    return 0;
  }
  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }
  sort(sndCosts.begin(), sndCosts.end());
  ll cost1 = accumulate(mins.begin(), mins.end(), 0LL);
  ll cost2 = accumulate(sndCosts.begin(), sndCosts.begin() + k-2, 0LL);
  ll cost = cost1 + cost2;
  // cout << cost1 << endl;
  // cout << cost2 << endl;
  cout << cost << endl;

  return 0;
}

