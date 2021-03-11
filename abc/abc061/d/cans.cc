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

ll INF = (ll)(1e15);

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, M; cin >> N >> M;
  vector<vector<pair<int, int>>> fwd(N), bwd(N);
  for (ll i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c; a--; b--;
    fwd.at(a).emplace_back(b, c);
    bwd.at(b).emplace_back(a, c);
  }
  vector<bool> rcbl(N);
  stack<int> st;
  st.push(N-1);
  while (!st.empty()) {
    int x = st.top(); st.pop();
    if (rcbl.at(x)) continue;
    rcbl.at(x) = true;
    for (auto t : bwd.at(x)) {
      int y = t.first;
      if (rcbl.at(y)) continue;
      st.push(y);
    }
  }
  int nRcbl = 0;
  for (int i = 0; i < N; i++) if (rcbl.at(i)) nRcbl++;
  vector<ll> score(N, -INF);
  score.at(0) = 0;
  int n = 0;
  for ( ; n < nRcbl; n++) {
    int chgd = 0;
    for (int i = 0; i < N; i++) {
      if (!rcbl.at(i)) continue;
      if (score.at(i) == -INF) continue;
      DLOG("i", i);
      DLOG("fwd(i)", fwd.at(i));
      for (auto p : fwd.at(i)) {
	DLOG("p", p);
	int dest = p.first;
	int rew = p.second;
	if (!rcbl.at(dest)) continue;
	if (score.at(i) + rew > score.at(dest)) {
	  chgd = 1;
	  score.at(dest) = score.at(i) + rew;
	}
      }
    }
    DLOG("n = ", n);
    DLOG(score);
    if (chgd == 0) {
      cout << score.at(N-1) << endl;
      return 0;
    }
  }
  cout << "inf" << endl;
  return 0;
}

