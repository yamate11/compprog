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
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) {
    if (i % 2 == 0) cin >> A.at(i);
    else            cin >> B.at(i);
  }
  for (ll i = 0; i < N; i++) {
    if (i % 2 == 0) cin >> B.at(i);
    else            cin >> A.at(i);
  }
  ll K = (N+1) /2;
  ll cost = LLONG_MAX;
  for (ll x = 0; x < (1LL << N); x++) {
    if (__builtin_popcountll(x) != K) continue;
    vector<pair<ll, ll>> u, v, w;
    for (ll i = 0; i < N; i++) {
      if ((x >> i) & 1LL) u.emplace_back(A.at(i), i);
      else                v.emplace_back(B.at(i), i);
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    for (ll i = 0; i < K; i++) {
      w.push_back(move(u.at(i)));
      if (i < N/2) w.push_back(move(v.at(i)));
    }
    auto doit = [&]() -> void {
      for (ll i = 1; i < N; i++) if (w.at(i-1).first > w.at(i).first) return;
      ll cnt = 0;
      for (ll i = 0; i < N; i++) {
	for (ll j = i+1; j < N; j++) {
	  if (w.at(i).second > w.at(j).second) cnt++;
	}
      }
      cost = min(cost, cnt);
    };
    doit();
  }

  if (cost == LLONG_MAX) {
    cout << -1 << endl;
  }else {
    cout << cost << endl;
  }

  return 0;
}

