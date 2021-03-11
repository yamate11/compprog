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

  int N, K; cin >> N >> K;
  vector<vector<double>> p(N+1, vector<double>(K+1));
  vector<vector<double>> q(N+1, vector<double>(K+1));
  for (int k = 0; k <= K; k++) p.at(0).at(k) = 1.0;
  for (int n = 0; n <= N; n++) q.at(n).at(0) = 0.0;
  for (int n = 0; n < N; n++) {
    double pTop   = 1.0 / (double)(N - (n+1) + 1);
    double pOther = 1.0 - pTop;
    p.at(n+1).at(0) = pOther * p.at(n).at(0);
    for (int k = 0; k < K; k++) {
      p.at(n+1).at(k+1) =   pTop   * max( p.at(n).at(k), q.at(n).at(k+1) )
	                  + pOther * p.at(n).at(k+1);
      q.at(n+1).at(k+1) =   pTop   * max( p.at(n).at(k), q.at(n).at(k+1) )
	                  + pOther * q.at(n).at(k+1);
    }
  }
  for (int k = K; k >= 1; k--) {
    for (int n = N; n >= 1; n--) {
      if (p.at(n-1).at(k-1) >= q.at(n-1).at(k)) {
	cout << k << ", " << n << "\n";
	break;
      }
    }
  }


  return 0;
}

