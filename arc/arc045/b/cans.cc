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

  int N, M; cin >> N >> M;
  vector<int> S(M), T(M);
  vector<int> ev(N+1);
  for (int i = 0; i < M; i++) {
    int s, t; cin >> s >> t; s--; t--;
    S.at(i) = s;
    T.at(i) = t+1;
    ev.at(s)++;
    ev.at(t+1)--;
  }
  vector<int> cum(N+1);
  cum.at(0) = ev.at(0);
  for (int i = 1; i <= N; i++) {
    cum.at(i) = cum.at(i-1) + ev.at(i);
  }
  assert(cum.at(N) == 0);
  vector<int> sOne, tOne;
  for (int j = 0; true; ) {
    for ( ; j < N && cum.at(j) >= 2; j++) ;
    if (j == N) break;
    sOne.push_back(j);
    for ( ; j < N && cum.at(j) == 1; j++) ;
    tOne.push_back(j);
  }
  DLOG("cum", cum);
  DLOG("sOne", sOne);
  DLOG("tOne", tOne);
  vector<int> sat;
  for (int i = 0; i < M; i++) {
    auto it = lower_bound(sOne.begin(), sOne.end(), S.at(i));
    int k = it - sOne.begin();
    if (k < (int)sOne.size() && sOne.at(k) < T.at(i)) continue;
    if (k-1 >= 0 && S.at(i) < tOne.at(k-1)) continue;
    sat.push_back(i);
  }
  cout << sat.size() << endl;
  for (int m : sat) cout << m+1 << endl;

  return 0;
}

