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

  ll N; cin >> N;
  vector<double> X(N);
  vector<double> Y(N);
  double xMax = 0;
  double xMin = 1000;
  double yMax = 0;
  double yMin = 1000;
  for (ll i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
    xMax = max(xMax, X.at(i));
    yMax = max(yMax, Y.at(i));
    xMin = min(xMin, X.at(i));
    yMin = min(yMin, Y.at(i));

  }
  double err = 1e-9;

  auto getR = [&](double x0, double y0) -> double {
    double ret = 0.0;
    for (int i = 0; i < N; i++) {
      double xd = X.at(i) - x0;
      double yd = Y.at(i) - y0;
      ret = max(ret, xd*xd + yd*yd);
    }
    return sqrt(ret);
  };

  double xc = (xMax + xMin) / 2;
  double yc = (yMax + yMin) / 2;
  double s = max(xMax - xMin, yMax - yMin) / 2;
  double rMin = 10000;
  while (true) {
    double rPrev = rMin;
    double xB;
    double yB;
    int div = 64;
    rMin = 10000;
    for (int i = -div; i <= div; i++) {
      for (int j = -div; j <= div; j++) {
	double r = getR(xc + i * s / div, yc + j * s / div);
	if (r < rMin) {
	  xB = xc + i * s / div;
	  yB = yc + j * s / div;
	  rMin = r;
	}
      }
    }
    xc = xB + s/6;
    yc = yB + s/6;
    s /= 2;
    DLOG("xysr", xc, yc, s, rMin);
    if (abs(rMin - rPrev) < err) break;
  }

  cout << rMin << endl;
  return 0;
}

