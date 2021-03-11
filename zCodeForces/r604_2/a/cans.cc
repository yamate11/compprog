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


char rest(char x, char y) {
  vector<bool> v(3);
  auto f = [&](char z) {
    if (z == 'a') v.at(0) = true;
    if (z == 'b') v.at(1) = true;
    if (z == 'c') v.at(2) = true;
  };
  f(x);
  f(y);
  char ret = !v.at(0) ? 'a' : !v.at(1) ? 'b' : 'c';
  DLOG("rest", x, y, ret);
  return ret;
}

string solve() {
  string s; cin >> s;
  int k = s.size();
  char buf[k + 1]; buf[k] = 0;
  char prev = 'z';
  for (int i = 0; i < k; i++) {
    if (s.at(i) == '?') {
      if (i + 1 < k && s.at(i+1) != '?') {
	buf[i] = prev = rest(prev, s.at(i+1));
      }else {
	buf[i] = prev = rest(prev, 'z');
      }
    }else {
      if (i > 0 && s.at(i-1) == s.at(i)) {
	return "-1";
      }
      buf[i] = prev = s.at(i);
    }
  }
  return buf;
}



int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    cout << solve() << "\n";
  }

  return 0;
}

