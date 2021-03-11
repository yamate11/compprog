#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


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


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector<ll> A(N), S(N+1), B(N+1);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  S.at(0) = 0;
  B.at(0) = 0;
  for (int i = 0; i < N; i++) {
    S.at(i+1) = (S.at(i) + A.at(i)) % K;
    int j = (i + 1) % K;
    B.at(i+1) = (K + S.at(i+1) - j) % K;
  }
  ll cnt = 0;

  unordered_map<ll,ll> mp;
  for (int i = 0; i <= N; i++) {
    int b = B.at(i);
    cnt += mp[b];
    mp[b]++;
    if (i - K + 1 >= 0) {
      int bb = B.at(i-K+1);
      mp[bb]--;
    }
  }
  cout << cnt << endl;
    
  return 0;
}

