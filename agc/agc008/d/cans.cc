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



typedef pair<int, int> Pair;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> A(N*N, -1);
  DLOG("A", A);
  vector<Pair> pos;
  for (int i = 0; i < N; i++) {
    int x; cin >> x; x--;
    pos.emplace_back(x, i);
    A.at(x) = i;
  }
  sort(pos.begin(), pos.end());
  DLOG("pos", pos);
  int cur = 0;
  DLOG("start", A);
  for (int i = 0; i < N; i++) {
    DLOG("i", i, "A", A);
    int p = pos.at(i).first;
    int y = pos.at(i).second;
    DLOG("p,y", p, y);
    for (int j = 0; j < y; j++) {
      while (cur < N*N && A.at(cur) >= 0) cur++;
      if (cur >= p) {
	cout << "No\n";
	return 0;
      }
      A.at(cur) = y;
    }
  }
  DLOG("half", A);
  cur = N*N - 1;
  for (int i = N-1; i >= 0; i--) {
    int p = pos.at(i).first;
    int y = pos.at(i).second;
    for (int j = 0; j < N - y - 1; j++) {
      while (cur >= 0 && A.at(cur) >= 0) cur--;
      if (cur <= p) {
	cout << "No\n";
	return 0;
      }
      A.at(cur) = y;
    }
  }
  DLOG("full", A);
  cout << "Yes\n";
  for (int i = 0; i < N*N; i++) {
    if (i > 0) cout << " ";
    cout << A.at(i) + 1;
  }
  cout << endl;


  return 0;
}

