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

typedef pair<ll, ll> Pair;

ll solve() {
  ll N, X, D; cin >> N >> X >> D;
  if (D == 0 && X == 0) return 1;
  if (D == 0) return N+1;
  if (D < 0) {
    X = X + (N-1) * D;
    D = -D;
  }

  map<ll, vector<Pair>> rec;
  bool zeroP = false;
  ll xshift = X % D;
  if (xshift < 0) xshift += D;
  for (ll k = 1; k <= N; k++) {
    // l * D + k * X ... r * D + k * X     step = D
    ll l = (k-1) * k / 2;
    ll r = (2*N - k - 1) * k /2;
    ll q = (k * xshift) % D;
    ll left  = l + (k * X - q) / D;
    ll right = r + (k * X - q) / D;
    if (q == 0 && left <= 0 && right >= 0) zeroP = true;
    rec[q].emplace_back(left, right);
  }
  ll cnt = 0;
  for (auto z : rec) {
#if DEBUG    
    ll q = z.first;
#endif
    auto vec = z.second;
    sort(vec.begin(), vec.end());
    DLOG("q", q, "vec", vec);
    ll prev = LLONG_MIN;
    for (Pair w : vec) {
      ll l = w.first;
      ll r = w.second;
      if (r <= prev) continue;
      cnt += r - max(l-1, prev);
      prev = r;
    }
  }
  if (!zeroP) cnt++;
  return cnt;

}


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;
  return 0;
}

