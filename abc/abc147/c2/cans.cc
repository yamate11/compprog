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
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<vector<int>> p(N);
  vector<vector<int>> q(N);
  for (int i = 0; i < N; i++) {
    int t; cin >> t;
    for (int j = 0; j < t; j++) {
      int x, y; cin >> x >> y; x--;
      p.at(i).push_back(x);
      q.at(i).push_back(y);
      DLOG("p,i,j,x", i, j, x);
      DLOG("q,i,j,x", i, j, y);
    }
  }

  auto countbit = [&](int x) -> int {
    int a = 0;
    for (int i = 0; i < N; i++) {
      if (x & (1 << i)) a++;
    }
    return a;
  };


  auto consis = [&](int s) -> bool {
    DLOG("checking", s);
    for (int j = 0; j < N; j++) {
      if (s & (1 << j)) {
	for (int k = 0; k < (int)p.at(j).size(); k++) {
	  DLOG("k", k);
	  int u = p.at(j).at(k);
	  int v = q.at(j).at(k);
	  if (((s >> u) & 1) != v) {
	    DLOG("j = ", j, "returning false", "u", u, "v", v, "k", k);
	    return false;
	  }
	  DLOG("ok");
	}
      }
    }
    return true;
  };
  
  int ans = 0;
  for (int s = 0; s < 1 << N; s++) {
    if (consis(s)) {
      DLOG("s", s, "consis");
      ans = max(ans, countbit(s));
    }else {
      DLOG("s", s, "inconsis");
    }
  }
  cout << ans << endl;
  return 0;
}

