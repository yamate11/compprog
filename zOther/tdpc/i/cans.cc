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

void updMax(auto& x, auto y) { x = max(x, y); }

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s ; cin >> s;
  int N = s.size();

  vector<vector<int>> rem(N, vector<int>(N+1, -1));
  
  auto func = fix([&](auto recF, int x, int y) -> int {
      DLOG("func", x, y);
      assert(x <= y);
      if (y - x <= 2) return 0;
      int& ref = rem.at(x).at(y);
      if (ref >= 0) return ref;

      ref = max(recF(x+1, y), recF(x, y-1));
      if (s.at(x) != 'i' || s.at(y-1) != 'i') return ref;
      if (x + 3 == y) {
	ref = s.at(x+1) == 'w' ? 1 : 0;
	return ref;
      }
      for (int t = x + 3; t <= y-3; t++) updMax(ref, recF(x, t) + recF(t, y));
      if ((y - x) % 3 != 0) return ref;
      for (int t = x + 1; t <= y - 1; t += 3) {
	if (s.at(t) == 'w' && recF(x+1, t) == (t - x) / 3
	    && recF(t+1, y-1) == (y-t-2) / 3) {
	  ref = (t - x) / 3 + (y-t-2) / 3 + 1;
	  return ref;
	}
      }
      return ref;
    });

  cout << func(0, N) << endl;
  return 0;
}

