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


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double xx, yy; cin >> xx >> yy;
  ll N; cin >> N;
  vector<double> x(N), y(N);
  for (ll i = 0; i < N; i++) cin >> x.at(i) >> y.at(i);
  double ans = DBL_MAX;
  for (ll i = 0; i < N; i++) {
    ll j = (i + 1) % N;
    double vx = x.at(j) - x.at(i);
    double vy = y.at(j) - y.at(i);
    auto dist = [&](double t) -> double {
      double dx = x.at(i) + vx * t - xx;
      double dy = y.at(i) + vy * t - yy;
      return sqrt(dx*dx + dy*dy);
    };
    double t = - (vx * (x.at(i) - xx) + vy * (y.at(i) - yy)) / (vx*vx + vy*vy);
    DLOG("vx, vy, t", vx, vy, t);
    double d = t < 0 ? dist(0) :
               t > 1 ? dist(1) :
                       dist(t) ;
    DLOG("d", d);
    ans = min(ans, d);
  }
  cout << ans << endl;
  return 0;
}

