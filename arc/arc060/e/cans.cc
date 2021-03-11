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

  int N; cin >> N;
  N++;
  vector<ll> X(N);
  for (int i = 0; i < N - 1; i++) cin >> X.at(i);
  X.at(N-1) = X.at(N-2) + 1;
  ll L; cin >> L;
  int Q; cin >> Q;

  vector<vector<int>> D;
  D.push_back(vector<int>(N));
  auto setZero = [&]() {
    int i = 0;
    for (int j = 0; j < N; j++) {
      while(i+1 < N && X.at(i+1) - X.at(j) <= L) i++;
      D.at(0).at(j) = i;
    }
  };
  setZero();
  DLOG("D.at(0)", D.at(0));
  auto setAbove = [&]() -> int {
    int k = 0;
    for ( ; D.at(k).at(0) < N-1; k++) {
      D.push_back(vector<int>(N));
      for (int i = 0; i < N; i++) {
	D.at(k+1).at(i) = D.at(k).at(D.at(k).at(i));
      }
      DLOG("k+1", k+1, "D.at(k+1)", D.at(k+1));
    }
    return k;
  };
  int K = setAbove();
  for (int q = 0; q < Q; q++) {
    int d = 0;
    int c, g; cin >> c >> g; c--; g--;
    if (c > g) swap(c, g);
    while (true) {
      if (c == g) {
	cout << d << "\n";
	break;
      }
      if (g <= D.at(0).at(c)) {
	cout << d + 1 << "\n";
	break;
      }
      int k = 0;
      for ( ; k+1 <= K && D.at(k+1).at(c) <= g ; k++) ;
      d += 1 << k;
      c = D.at(k).at(c);
    }
  }

  return 0;
}

