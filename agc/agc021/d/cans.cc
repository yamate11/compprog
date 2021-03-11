#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

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
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  int K; cin >> K;

  int N = S.size();
  vector<vector<vector<int>>>
    dp(N+2, vector<vector<int>>(N+2, vector<int>(K+1, -1)));
  for (int j = 0; j < N+1; j++) {
    for (int k = 0; k < K+1; k++) {
      dp.at(0).at(j).at(k) = dp.at(j).at(N+1).at(k) = 0;
    }
  }
  auto f = fix([&](auto recF, int i, int j, int k) -> int {
      int& ref = dp.at(i).at(j).at(k);
      if (ref < 0) {
	if (S.at(i-1) == S.at(j-1)) {
	  ref = 1 + recF(i-1, j+1, k);
	}else {
	  int t = max(recF(i-1, j, k), recF(i, j+1, k));
	  if (k > 0) ref = max(t, 1 + recF(i-1, j+1, k-1));
	  else       ref = t;
	}
	DLOG("f: ", i, j, k, " -> ", ref);
      }
      return ref;
    });
  int ans = 0;
  for (int i = 1; i <= N; i++) ans = max(ans, 2 * f(i, i, K) - 1);
  for (int i = 1; i <  N; i++) ans = max(ans, 2 * f(i, i+1, K));
  cout << ans << endl;

  return 0;
}

