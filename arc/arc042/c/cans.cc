#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

using Pair = pair<ll, ll>;

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

  ll N, P; cin >> N >> P;
  vector<Pair> item;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    item.emplace_back(a, b);
  }
  sort(item.begin(), item.end(), greater<Pair>());
  vector<ll> dp(P + item.at(0).first + 1, -1);
  dp.at(0) = 0;
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll price = item.at(i).first;
    ll sat = item.at(i).second;
    for (ll j = P + price; j - price >= 0; j--) {
      ll s = dp.at(j - price);
      if (s >= 0) {
	dp.at(j) = max(dp.at(j), s + sat);
	ans = max(ans, dp.at(j));
      }
    }
    DLOG(dp);
  }
  cout << ans << endl;

  return 0;
}

