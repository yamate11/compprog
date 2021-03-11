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
  vector<ll> C(N+1);

  for (ll i = 1; i <= N; i++) cin >> C.at(i);
  ll Q; cin >> Q;
  ll ans = 0;
  for (int j = 1; j <= Q; j++) {
    ll t; cin >> t;
    if (t == 1) {
      ll x, a; cin >> x >> a;
      if (a <= C.at(x)) {
	C.at(x) -= a;
	ans += a;
      }
    }else if (t == 2) {
      ll a; cin >> a;
      bool ok = true;
      for (int i = 1; i <= N; i++) {
	if (i % 2 == 0) continue;
	if (a > C.at(i)) {
	  ok = false;
	  break;
	}
      }
      if (ok) {
	for (int i = 1; i <= N; i++) {
	  if (i % 2 == 0) continue;
	  C.at(i) -= a;
	  ans += a;
	}
      }
    }else if (t == 3) {
      ll a; cin >> a;
      bool ok = true;
      for (int i = 1; i <= N; i++) {
	if (a > C.at(i)) {
	  ok = false;
	  break;
	}
      }
      if (ok) {
	for (int i = 1; i <= N; i++) {
	  C.at(i) -= a;
	  ans += a;
	}
      }
    }
  }
  cout << ans << endl;
  return 0;
}

