#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// --- DEBUG begin --- cut here ---
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

// operator<< definitions for some classes

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}
// --- DEBUG end --- cut here ---


// --- FIX begin --- cut here ---
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
// --- FIX end --- cut here ---


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<vector<ll>> A(N, vector<ll>(N));
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int a; cin >> a;
      A.at(i).at(j) = A.at(j).at(i) = a;
    }
  }
  vector<ll> grp(1<<N);
  auto setGrp = fix([&](const auto& recF, int vs, int m, ll curV) -> void {
      for (int n = 0; n < m; n++) {
	if (vs & (1 << n)) curV += A.at(n).at(m);
      }
      int newVs = vs | (1 << m);
      grp.at(newVs) = curV;
      for (int k = m + 1; k < N; k++) recF(newVs, k, curV);
    });
  grp.at(0) = 0;
  for (int m = 0; m < N; m++) setGrp(0, m, 0);
  DLOG("grp", grp);

  ll ans = LLONG_MIN;
  int full = (1 << N) - 1;
  for (int x = 0; x <= full; x++) {
    int rem = full ^ x;
    for (int y = rem; 1; y = rem & (y - 1)) {
      int z = rem ^ y;
      ans = max(ans, grp.at(x) + grp.at(y) + grp.at(z));
      if (y == 0) break;
    }
  }
  cout << ans << endl;

  return 0;
}

