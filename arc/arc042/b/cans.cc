#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

using Complex = complex<double>;

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

double distPtSeg(Complex pt, Complex s1, Complex s2) {
  double len = abs(s2 - s1);
  Complex v = (s2 - s1) / len;
  Complex rPt = (pt - s1) / v;
  double x = rPt.real();
  double d = x < 0 ? abs(pt - s1) : x > len ? abs(pt - s2) : abs(rPt.imag());
  return d;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double xx, yy; cin >> xx >> yy;
  Complex pt(xx, yy);
  ll N; cin >> N;
  vector<Complex> e;
  for (ll i = 0; i < N; i++) {
    double x, y; cin >> x >> y;
    e.emplace_back(x, y);
  }
  double ans = DBL_MAX;
  for (ll i = 0; i < N; i++) {
    double d = distPtSeg(pt, e.at(i), e.at((i + 1) % N));
    ans = min(ans, d);
  }
  cout << ans << endl;
  return 0;
}

