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



using Tuple = tuple<ll, int, int>;
using Pair = pair<int, int>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());

  vector<ll> sum(N+1);
  for (int i = 0; i < N; i++) {
    sum.at(i+1) = sum.at(i) + A.at(i);
  }
  if (M == N*N) {
    cout << 2 * N * sum.at(N) << endl;
    return 0;
  }
  
  auto chk = [&](ll bnd, ll& count) -> bool {
    DLOG("chk called", bnd);
    count = 0;
    for (int i = 0; i < N; i++) {
      auto it = lower_bound(A.begin(), A.end(), bnd - A.at(i));
      int idx = it - A.begin();
      DLOG("i, idx", i, idx);
      count += N - idx;
    }
    DLOG("chk count", count);
    return count <= M;
  };

  ll count;
  ll ok = A.at(N-1) + A.at(N-1) + 1;
  ll ng = A.at(0) + A.at(0);
  while (ng+1 < ok) {
    ll mid = (ok + ng) / 2;
    if (chk(mid, count)) ok = mid;
    else                 ng = mid;
  }
  ll sat = 0;
  for (int i = 0; i < N; i++) {
    auto it = lower_bound(A.begin(), A.end(), ok - A.at(i));
    int idx = it - A.begin();
    sat += (N - idx) * A.at(i) + sum.at(N) - sum.at(idx);
  }
  chk(ok, count);
  cout << sat + (M - count) * (ok - 1) << endl;

  return 0;
}

