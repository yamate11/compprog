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


ll popcount(ll x) {
  ll cnt = 0;
  for (ll i = 0; i < 32; i++) {
    if (x & (1LL << i)) cnt++;
  }
  return cnt;
}

ll pwr(ll b, ll r) {
  ll ans = 1;
  for (ll i = 0; i < r; i++) ans *= b;
  return ans;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<vector<ll>> nbr(N);
  map<pair<ll, ll>, ll> ename;
  for (ll i = 0; i < N-1; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
    ename[make_pair(a, b)] = i;
    ename[make_pair(b, a)] = i;
  }
  vector<ll> parent(N);
  auto storeParent = [&](const auto& recF, ll i, ll p) -> void {
    parent.at(i) = p;
    for (ll c : nbr.at(i)) {
      if (c == p) continue;
      recF(recF, c, i);
    }
  };
  storeParent(storeParent, 0, -1);
  vector<vector<ll>> pseq(N);
  for (ll i = 0; i < N; i++) {
    for (ll j = i; j >= 0; j = parent.at(j)) {
      pseq.at(i).push_back(j);
    }
  }

  ll M; cin >> M;
  vector<vector<ll>> plan(N-1, vector<ll>(M));
  for (ll j = 0; j < M; j++) {
    ll u, v; cin >> u >> v; u--; v--;
    ll ul = pseq.at(u).size();
    ll vl = pseq.at(v).size();
    ll k = 1;
    for (;
	 ul-k >= 0 && vl-k >= 0 &&
	 pseq.at(u).at(ul-k) == pseq.at(v).at(vl-k);
	 k++);
    k--;
    ll ca = pseq.at(u).at(ul-k);
    for (ll uu = u; uu != ca; uu = parent.at(uu)) {
      ll p = parent.at(uu);
      plan.at(ename[make_pair(uu, p)]).at(j) = true;
    }
    for (ll uu = v; uu != ca; uu = parent.at(uu)) {
      ll p = parent.at(uu);
      plan.at(ename[make_pair(uu, p)]).at(j) = true;
    }
  }
  DLOG("plan", plan);
  ll cnt = 0;
  for (ll x = 1; x < (1L << M); x++) {
    vector<bool> vec(N-1);
    for (ll i = 0; i < M; i++) {
      if (!(x & (1L << i))) continue;
      for (ll e = 0; e < N-1; e++) {
	vec.at(e) = vec.at(e) || plan.at(e).at(i);
      }
    }
    ll c = 0;
    for (ll e = 0; e < N-1; e++) if (vec.at(e)) c++;
    DLOG("x, c", x, c);
    ll thisCnt = pwr(2, N-1 - c);
    if (popcount(x) % 2 == 1) cnt += thisCnt;
    else                      cnt -= thisCnt;
  }
  cout << pwr(2, N-1) - cnt << endl;

  return 0;
}

