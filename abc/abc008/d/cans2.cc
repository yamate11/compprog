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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll W, H; cin >> W >> H;
  ll N; cin >> N;
  vector<ll> X(N), Y(N), oX(N), oY(N), rX(N), rY(N);
  for (ll i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
    X.at(i)--;
    Y.at(i)--;
  }
  iota(oX.begin(), oX.end(), 0);
  iota(oY.begin(), oY.end(), 0);
  sort(oX.begin(), oX.end(),
       [&](ll p, ll q) -> bool { return X.at(p) < X.at(q); });
  sort(oY.begin(), oY.end(),
       [&](ll p, ll q) -> bool { return Y.at(p) < Y.at(q); });
  for (ll i = 0; i < N; i++) {
    rX.at(oX.at(i)) = i;
    rY.at(oY.at(i)) = i;
  }
  DLOG("oX", oX);
  DLOG("oY", oY);
  DLOG("rX", rX);
  DLOG("rY", rY);
  auto expX = [&](ll p) -> ll {
    if (p == -1) return -1;
    if (p == N) return W;
    return X.at(oX.at(p));
  };
  auto expY = [&](ll q) -> ll {
    if (q == -1) return -1;
    if (q == N) return H;
    return Y.at(oY.at(q));
  };

  using Vec1 = vector<ll>;
  using Vec2 = vector<Vec1>;
  using Vec3 = vector<Vec2>;
  using Vec4 = vector<Vec3>;
  Vec4 tbl(N+2, Vec3(N+2, Vec2(N+2, Vec1(N+2, -1))));
  auto f = [&](const auto& recF, ll p0, ll p1, ll q0, ll q1) -> ll {
    ll& r = tbl.at(p0+1).at(p1+1).at(q0+1).at(q1+1);
    bool found = false;
    if (r < 0) {
      ll vmax = 0;
      for (ll i = 0; i < N; i++) {
	ll pp = rX.at(i);
	ll qq = rY.at(i);
	// DLOG("i", i, "pp", pp, "qq", qq);
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
	ll gath = (expX(p1) - expX(p0) - 1)
	  +       (expY(q1) - expY(q0) - 1)   - 1;
	DLOG("gath", gath, expX(p1), expX(p0), expY(q1), expY(q0));
	r = gath + vmax;
      }
    }
    DLOG("f RET", r, p0, p1, q0, q1);
    return r;
  };
  cout << f(f, -1, N, -1, N) << endl;

  return 0;
}

