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
  int N, M; cin >> N >> M;
  vector<int> A(N), B(M);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i); A.at(i)--;
  }
  for (int i = 0; i < M; i++) {
    cin >> B.at(i); B.at(i)--;
  }
  DLOG("A", A);
  DLOG("B", B);
  vector<int> oB(N, -1);
  for (int i = 0; i < M; i++) oB.at(B.at(i)) = i;
  DLOG("oB", oB);
  int hi = 0;
  ll ans = 0;
  vector<bool> handled(M);
  for (int i = 0; i < N; i++) {
    int b = oB.at(A.at(i));
    if (b == -1) continue;
    if (b == hi) {
      ans += 2 * (i - hi) + 1;
      handled.at(hi) = true;
      hi++;
      while (hi < M && handled.at(hi)) hi++;
      if (hi == M) break;
      DLOG("b == hi", i, b, hi, ans);
      continue;
    }else {
      handled.at(b) = true;
      ans += 1;
      DLOG("b != hi", i, b, hi, ans);
    }
  }
  return ans;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int t; cin >> t;
  for (int z = 0; z < t; z++) cout << solve() << "\n";

  return 0;
}

