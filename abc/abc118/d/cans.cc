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

//-----fix-----cut here-----cut here--
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
//-----fix--------cut here-----cut here--

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<int> use({0,2,5,5,4,5,6,3,7,6});
  int N, M; cin >> N >> M;
  vector<bool> ex(10);
  int minU = 10;
  for (int i = 0; i < M; i++) {
    int a; cin >> a;
    ex.at(a) = true;
    minU = min(minU, use.at(a));
  }
  if (ex.at(2) && (ex.at(3) || ex.at(5))) ex.at(2) = false;
  if (ex.at(3) && ex.at(5)) ex.at(3) = false;
  if (ex.at(6) && ex.at(9)) ex.at(6) = false;
  vector<int> vEx;
  for (int i = 1; i <= 9; i++) if (ex.at(i)) vEx.push_back(i);
  int esize = vEx.size();
  vector<vector<int>>
    res(esize, vector<int>(N+1, -1)), acc(esize + 1, vector<int>(N+1, -1));
  acc.at(0).at(0) = 0;
  for (int i = 0; i < esize; i++) {
    int a = vEx.at(i);
    int u = use.at(a);
    for (int x = 0; x <= N; x++) {
      int vmax = -1;
      int arg = -1;
      for (int k = 0; x - k * u >= 0; k++) {
	int prev = acc.at(i).at(x - k*u);
	if (prev < 0) continue;
	if (prev + k >= vmax) {
	  vmax = prev + k;
	  arg = k;
	}
      }
      res.at(i).at(x) = arg;
      acc.at(i+1).at(x) = vmax;
    }
    DLOG("i", i);
    DLOG("res", res.at(i));
    DLOG("acc", acc.at(i+1));
  }
  int n = N;
  for (int i = esize-1; i >= 0; i--) {
    for (int p = 0; p < res.at(i).at(n); p++) cout << vEx.at(i);
    n -= res.at(i).at(n) * use.at(vEx.at(i));
  }
  cout << endl;

  return 0;
}

