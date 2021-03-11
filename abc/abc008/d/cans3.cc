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

template <typename T>
struct compCoord {
  vector<T> vec;
  vector<int> ord;
  map<T, int> comp_;
  compCoord(const auto& vec_) {
    vec.resize(vec_.size());
    ord.resize(vec_.size());
    for (int i = 0; i < (int)vec_.size(); i++) vec.at(i) = vec_.at(i);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(),
	 [&](int p, int q) { return vec.at(p) < vec.at(q); });
    for (int i = 0; i < (int)vec.size(); i++) comp_[vec.at(ord.at(i))] = i;
  }
  int comp(T x) const { return comp_.at(x); }
  T expand(int i) const { return vec.at(ord.at(i)); }
};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll W, H; cin >> W >> H;
  ll N; cin >> N;
  vector<ll> X(N), Y(N);
  for (ll i = 0; i < N; i++) cin >> X.at(i) >> Y.at(i);
  X.push_back(0);
  X.push_back(W+1);
  Y.push_back(0);
  Y.push_back(H+1);
  compCoord<ll> cmpX(X), cmpY(Y);
  using Vec1 = vector<ll>;
  using Vec2 = vector<Vec1>;
  using Vec3 = vector<Vec2>;
  using Vec4 = vector<Vec3>;
  Vec4 tbl(N+2, Vec3(N+2, Vec2(N+2, Vec1(N+2, -1))));
  auto f = [&](const auto& recF, ll p0, ll p1, ll q0, ll q1) -> ll {
    ll& r = tbl.at(p0).at(p1).at(q0).at(q1);
    bool found = false;
    if (r < 0) {
      ll vmax = 0;
      for (ll i = 0; i < N; i++) {
	ll pp = cmpX.comp(X.at(i));
	ll qq = cmpY.comp(Y.at(i));
	if (!(p0 < pp && pp < p1 && q0 < qq && qq < q1)) continue;
	found = true;
	ll v = recF(recF, p0, pp, q0, qq)
	  +    recF(recF, p0, pp, qq, q1)
	  +    recF(recF, pp, p1, q0, qq)
	  +    recF(recF, pp, p1, qq, q1);
	vmax = max(vmax, v);
      }
      if (!found) r = 0;
      else {
	ll gath = (cmpX.expand(p1) - cmpX.expand(p0) - 1)
	  +       (cmpY.expand(q1) - cmpY.expand(q0) - 1)  - 1;
	r = gath + vmax;
      }
    }
    return r;
  };
  cout << f(f, 0, N+1, 0, N+1) << endl;

  return 0;
}

