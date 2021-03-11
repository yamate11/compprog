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


double distance(double x1, double y1, double x2, double y2) {
  double x = x2 - x1;
  double y = y2 - y1;
  return sqrt(x*x + y*y);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double err = 1e-9;

  ll N; cin >> N;
  vector<double> X(N);
  vector<double> Y(N);
  for (ll i = 0; i < N; i++)  cin >> X.at(i) >> Y.at(i);

  auto distP = [&](ll i, ll j) -> double {
    return distance(X.at(i), Y.at(i), X.at(j), Y.at(j));
  };

  auto sat = [&](double x, double y, double r) -> bool {
    for (ll i = 0; i < N; i++) {
      if (distance(X.at(i), Y.at(i), x, y) > r + err) return false;
    }
    return true;
  };

  auto outCenter = [&](ll i, ll j, ll k, double& rX, double& rY, double& rR) {
    double x1 = X.at(j) - X.at(i);
    double y1 = Y.at(j) - Y.at(i);
    double x2 = X.at(k) - X.at(i);
    double y2 = Y.at(k) - Y.at(i);
    double p = x1 * x1 / 2 + y1 * y1 / 2;
    double q = x2 * x2 / 2 + y2 * y2 / 2;
    double u = x1 * y2 - x2 * y1;
    if (abs(u) < err) {
      rX = rY = 0;
      rR = DBL_MAX;
      return ;
    }
    double rrX = (p * y2 - q * y1) / u;
    double rrY = (p * x2 - q * x1) / (-u);
    rR = distance(rrX, rrY, 0, 0);
    rX = X.at(i) + rrX;
    rY = Y.at(i) + rrY;
    return;

  };

  double ans = DBL_MAX;
  for (ll i = 0; i < N; i++) {
    for (ll j = i+1; j < N; j++) {
      double d = distP(i, j) / 2;
      if (d < ans &&
	  sat((X.at(i) + X.at(j)) / 2, (Y.at(i) + Y.at(j)) / 2, d)) {
	ans = d;
      }
      for (ll k = j+1; k < N; k++) {
	double x, y, r;
	outCenter(i, j, k, x, y, r);
	if (r < ans && sat(x, y, r)) ans = r;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

