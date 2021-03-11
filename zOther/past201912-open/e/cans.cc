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

  int N, Q; cin >> N >> Q;
  vector<vector<bool>> f(N, vector<bool>(N));
  for (int q = 0; q < Q; q++) {
    int t; cin >> t;
    if (t == 1) {
      int a, b; cin >> a >> b; a--; b--;
      f.at(a).at(b) = true;
    }else if (t == 2) {
      int a; cin >> a; a--;
      for (int i = 0; i < N; i++) {
	if (f.at(i).at(a)) f.at(a).at(i) = true;
      }
    }else if (t == 3) {
      int a; cin >> a; a--;
      DLOG("FF", a);
      vector<bool> upd(N);
      for (int x = 0; x < N; x++) {
	if (x == a) continue;
	if (!f.at(a).at(x)) continue;
	DLOG("FF - x", x);
	for (int y = 0; y < N; y++) {
	  if (y == a) continue;
	  if (f.at(x).at(y)) {
	    DLOG("FF - y", y);
	    upd.at(y) = true;
	  }
	}
      }
      for (int i = 0; i < N; i++) if (upd.at(i)) f.at(a).at(i) = true;
    }else assert(false);
    DLOG(f);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << (f.at(i).at(j) ? 'Y' : 'N');
    }
    cout << "\n";
  }

  return 0;
}

