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

  ll N, K; cin >> N >> K;
  vector<ll> a(N), s(N+1);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
    s.at(i+1) = s.at(i) + a.at(i);
  }
  vector<vector<ll>> dp(N+1, vector<ll>(N+1, K+1));
  dp.at(0).at(0) = 0;
  for (int i = 0; i < N; i++) {
    dp.at(i+1).at(0) = 0;
    for (int j = 0; j < i + 1; j++) {
      ll x = (i == 0) ? 1
                      : 1 + dp.at(i).at(j) * s.at(i+1) / s.at(i);
      DLOG("i,j,x", i, j, x);
      if (x - dp.at(i).at(j) > a.at(i)) x = K+1;
      DLOG("dp.at(i).at(j), a.at(i)", dp.at(i).at(j), a.at(i), x);
      DLOG("s.at(N), s.at(i+1)", s.at(N), s.at(i+1));
      dp.at(i+1).at(j+1) = max(K - (s.at(N) - s.at(i+1)),
			       min(dp.at(i).at(j+1), x));
    }
  }
  DLOG("dp", dp);
  for (int i = N; i >= 0; i--) {
    if (dp.at(N).at(i) == K) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}

