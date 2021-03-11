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



/*
     xp +  q <= R 
      p + yq <= B

      p <= min(R/x, B)
      q <= min(B/y, R)

  eq:    p + y(R - xp) = B
         (xy - 1)p = yR - B
         x(B - yq) + q = R
         (xy - 1)q = xB - R

q = k - p
(x - 1)p <= R - k
(y - 1)p >= ky - B


 */

ll solve() {
  ll R, B, x, y; cin >> R >> B >> x >> y;
  ll ok = 0;
  ll ng = min(R/x, B) + min(B/y, R) + 1;

  auto chk = [&](ll k) {
    if (R < k) return false;
    ll p = min(k, (R - k) / (x - 1));
    bool b = p + y * (k - p) <= B;
    DLOG("chk", k, p, b);
    return b;
  };

  while (ok +1 < ng) {
    DLOG("bin", ok, ng);
    ll mid = (ok + ng) / 2;
    if (chk(mid)) ok = mid;
    else          ng = mid;
  }
  return ok;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

