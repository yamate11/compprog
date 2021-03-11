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

  string S; cin >> S;
  ll M = S.size();
  
  ll i = 0;
  ll sum = 0;

  if (S.at(0) == '>') {
    while (i < M && S.at(i) == '>') i++;
    sum = i * (i+1) / 2;
    if (i == M) {
      cout << sum << endl;
      return 0;
    }
  }

  auto getTwo = [&](ll i0, ll& len1, ll& len2) -> bool {
    len1 = 0;
    len2 = 0;
    ll j = i0;
    DLOG("j", j, "S", S, "S.at(j)", S.at(j));
    while (j < M && S.at(j) == '<') {
      j++;
      len1++;
    }
    if (j == M) return true;
    while (j < M && S.at(j) == '>') {
      j++;
      len2++;
    }
    if (j == M) return true;
    return false;
  };

  while (1) {
    ll len1 = 0;
    ll len2 = 0;
    bool fin = getTwo(i, len1, len2);
    ll len3 = max(len1, len2);
    ll len4 = min(len1, len2);
    sum += len3 * (len3 + 1) / 2;
    sum += len4 * (len4 - 1) / 2;
    i += len1 + len2;
    if (fin) break;
  }

  cout << sum << endl;

  return 0;
}

