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

void impossible() {
  cout << "No" << endl;
  exit(0);
};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> A(N), B(N), V(N, -1);
  vector<vector<int>> nbr(N);
  for (int i = 0; i < N-1; i++) {
    int a, b; cin >> a >> b; a--; b--;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }
  int K; cin >> K;
  for (int i = 0; i < K; i++) {
    int v, p; cin >> v >> p; v--;
    V.at(v) = p;
  }
  vector<bool> eff(N);
  auto chk = fix([&](const auto& recF, int n, int p) -> void {
      if (V.at(n) >= 0) {
	A.at(n) = B.at(n) = V.at(n);
	eff.at(n) = true;
      }
      for (int cld : nbr.at(n)) {
	if (cld == p) continue;
	recF(cld, n);
	if (!eff.at(cld)) continue;
	if (!eff.at(n)) {
	  A.at(n) = A.at(cld) - 1;
	  B.at(n) = B.at(cld) + 1;
	  eff.at(n) = true;
	}else {
	  if ((A.at(cld) - A.at(n)) % 2 == 0) {
	    DLOG("impossible_1", n);
	    impossible();
	  }
	  A.at(n) = max(A.at(n), A.at(cld) - 1);
	  B.at(n) = min(B.at(n), B.at(cld) + 1);
	  if (B.at(n) < A.at(n)) {
	    DLOG("impossible_2", n);
	    impossible();
	  }
	}
      }
      DLOG("chk returning", n, A.at(n), B.at(n), eff.at(n));
    });
  chk(0, -1);
  auto setV = fix([&](const auto& recF, int n, int p, int vp) -> void {
      if (!eff.at(n))                                  V.at(n) = vp + 1;
      else if (A.at(n) <= vp - 1 && vp - 1 <= B.at(n)) V.at(n) = vp - 1;
      else if (A.at(n) <= vp + 1 && vp + 1 <= B.at(n)) V.at(n) = vp + 1;
      else                                             assert(false);
      for (int cld : nbr.at(n)) {
	if (cld == p) continue;
	recF(cld, n, V.at(n));
      }
    });
  setV(0, -1, A.at(0) + 1);
  cout << "Yes" << endl;
  for (int n = 0; n < N; n++) cout << V.at(n) << "\n";

  return 0;
}

