#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug)
// --> f:<< debug
// ---- inserted function << from util.cc
template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ")";
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

template <typename T>
ostream& operator<< (ostream& os, const set<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const multiset<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const map<T1, T2>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
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
// ---- end <<
// ---- inserted library file debug.cc
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

// ---- end debug.cc
// @@ !! LIM  -- end mark --

template <typename T>  // T is typically int, ll, double, etc.
struct Dijkstra {
  int n;
  int orig;
  vector<T> vdist;

  Dijkstra(int n_, auto numNbr, auto dist, int orig_ = 0)
    : n(n_), orig(orig_), vdist(n, LLONG_MAX) { init(numNbr, dist); }

  void init(auto numNbr, auto dist) {
    using Pair = pair<T, int>;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pque;
    vdist.at(0) = 0;
    pque.emplace(0, orig);
    while (!pque.empty()) {
      Pair p = pque.top(); pque.pop();
      T d = p.first;
      int i = p.second;
      if (vdist.at(i) < d) continue;
      assert(vdist.at(i) == d);
      for (int j = 0; j < numNbr(i); j++) {
	auto pd = dist(i, j);
	T newDist = d + pd.second;
	int k = pd.first;
	if (vdist.at(k) <= newDist) continue;
	vdist.at(k) = newDist;
	pque.emplace(newDist, k);
	DLOG("pque.emplace", newDist, k);
      }
    }
  }

  T dist(int i) { return vdist.at(i); }
};



using Pair = pair<double, ll>;

double big = DBL_MAX;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<double> X(N), Y(N), T(N), R(N);
  for (ll i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i) >> T.at(i) >> R.at(i);
  }

  auto numNbr = [&](ll i) -> ll { return N; };
  auto dist = [&](ll i, ll j) -> pair<ll, double> {
    double d =
      hypot(X.at(i) - X.at(j), Y.at(i) - Y.at(j)) / min(T.at(i), R.at(j));
    return make_pair(j, d);
  };
  Dijkstra<double> dij(N, numNbr, dist);
  vector<double> time = move(dij.vdist);
  sort(time.begin(), time.end());
  double ans = 0;
  for (ll t = 1; t < N; t++) {
    ans = max(ans, time.at(t) + double(N-1 - t));
  }
  cout << ans << endl;

  return 0;
}

