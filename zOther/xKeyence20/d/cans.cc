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


void updMin(auto& x, const auto y) { x = min(x, y); }

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if DEBUG
  ll vmax = 4;
  ll big = 9;
#else
  ll vmax = 50;
  ll big = LLONG_MAX;
#endif

  ll N; cin >> N;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  for (ll i = 0; i < N; i++) cin >> B.at(i);
  vector<pair<ll, ll>> sets;
  for (ll x = 0; x < (1LL << N); x++) {
    sets.emplace_back(__builtin_popcountll(x), x);
  }
  sort(sets.begin(), sets.end());

  vector<vector<ll>> dp(1LL << N, vector<ll>(vmax+1, big));
  dp.at(0).at(0) = 0;
  for (auto z : sets) {
    ll x = z.second;
    ll p = z.first;
    for (ll r = 0; r <= vmax; r++) {
      if (dp.at(x).at(r) == big) continue;
      ll sft = 0;
      for (ll i = 0; i < N; i++) {
	if ((x >> i) & 1LL) {
	  sft++;
	  continue;
	}
	ll t = abs(i-p) % 2 == 0 ? A.at(i) : B.at(i);
	if (r > t) continue;
	updMin(dp.at(x | (1LL << i)).at(t), dp.at(x).at(r) + i - sft);
      }
    }
    DLOG("x", x);
    DLOG("dp", dp);
  }
  ll cost = big;
  for (ll r = 0; r <= vmax; r++) cost = min(cost, dp.at((1LL << N) - 1).at(r));

  cout << (cost == big ? -1 : cost) << endl;

  return 0;
}

