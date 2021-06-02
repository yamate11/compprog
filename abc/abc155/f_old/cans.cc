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

  ll N, M; cin >> N >> M;
  using Tup = tuple<ll, ll, ll>;
  vector<Tup> vec;
  vec.emplace_back(0, 0, 0);
  vec.emplace_back(1e9+10, 1, 0);
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    vec.emplace_back(a, 1, b);
  }
  for (ll i = 0; i < M; i++) {
    ll l, r; cin >> l >> r;
    vec.emplace_back(l, 0, i);
    vec.emplace_back(r, 2, i);
  }
  sort(vec.begin(), vec.end());
  vector<bool> flip(N+1);
  vector<ll> Lm(M), Rm(M);
  vector<vector<ll>> nbr(N+1);
  // unordered_map<ll, unordered_map<ll, ll>> edge;
  map<ll, map<ll, ll>> edge;
  ll cPos = 0;
  ll cSw = 0;
  for (auto t : vec) {
    ll x, type, sw; tie(x, type, sw) = t;
    if (type == 1) {
      flip.at(cPos) = cSw != sw;
      cSw = sw;
      cPos++;
    }else if (type == 0) {
      Lm.at(sw) = cPos;
    }else if (type == 2) {
      Rm.at(sw) = cPos;
      if (Lm.at(sw) != Rm.at(sw)) {
	nbr.at(Lm.at(sw)).push_back(Rm.at(sw));
	nbr.at(Rm.at(sw)).push_back(Lm.at(sw));
	edge[Lm.at(sw)][Rm.at(sw)] = edge[Rm.at(sw)][Lm.at(sw)] = sw;
      }
    }else assert(0);
  }
  DLOG("flip", flip);
  DLOG("edge", edge);
  vector<ll> ans;
  vector<bool> seen0(N+1);
  for (ll i = 0; i <= N; i++) {
    if (seen0.at(i)) continue;
    auto dfsCnt = [&](const auto& recF, ll n, ll p) -> bool {
      DLOG("dfsCnt", n, p);
      // Returns whether the number is odd.
      if (seen0.at(n)) {
	DLOG("dfsCnt", n, p, "immediately returns");
	return false;
      }
      seen0.at(n) = true;
      ll c = flip.at(n) ? 1 : 0;
      for (ll m : nbr.at(n)) {
	if (m == p) continue;
	if (recF(recF, m, n)) {
	  ans.push_back(edge.at(m).at(n));
	  c++;
	}
      }
      bool b = c % 2 == 1;
      DLOG("dfsCnt", n, p, "returns", b);
      return b;
    };
    if (dfsCnt(dfsCnt, i, -1)) {
      cout << "-1\n";
      exit(0);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (ll i = 0; i < (ll)ans.size(); i++) {
    if (i > 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;

  return 0;
}

