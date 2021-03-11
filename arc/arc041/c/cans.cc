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


ll solve() {
  ll N, L; cin >> N >> L;
  vector<ll> X(N);
  vector<char> D(N);
  for (ll i = 0; i < N; i++) {
    ll x; cin >> x; x--; X.at(i) = x;
    cin >> D.at(i);
  }
  auto cntLeft = [&](ll ib, ll ie, ll bnd) -> ll {
    ll ret = 0;
    for (ll j = 0; ib + j < ie; j++) ret += X.at(ib + j) - bnd - j;
    return ret;
  };
  auto cntRight = [&](ll ib, ll ie, ll bnd) -> ll {
    ll ret = 0;
    for (ll j = 0; ib + j < ie; j++) ret += bnd-1 - X.at(ib + j) - j;
    return ret;
  };

  ll cnt = 0;
  for (ll i = 0; i < N; ) {
    ll bL = i;
    while (i < N && D.at(i) == 'R') i++;
    ll bC = i;
    ll bndL = bC-1 >= 0 ? X.at(bC-1) + 1 : 0;
    ll bndR = bC < N    ? X.at(bC)       : L;
    while (i < N && D.at(i) == 'L') i++;
    ll bR = i;
    ll bnd = (bC - bL <= bR - bC) ? bndL : bndR;
    DLOG("LCR", bL, bC, bR, bnd);
    cnt += cntRight(bL, bC, bnd);
    DLOG("cnt1", cnt);
    cnt += cntLeft(bC, bR, bnd);
    DLOG("cnt2", cnt);
  }
  return cnt;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

