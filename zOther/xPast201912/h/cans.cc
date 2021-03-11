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
  vector<int> C(N+1);
  set<int> odd;
  set<int> even;
  for (int i = 1; i <= N; i++) {
    int c; cin >> c;
    C.at(i) = c;
    if (i % 2 == 0) even.insert(c);
    else            odd.insert(c);
  }
  int oddShift = 0;
  int evenShift = 0;

  ll ans = 0;
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int t; cin >> t;
    if (t == 1) {
      ll x, a; cin >> x >> a;
      DLOG("*IN*", 1, x, a);
      int p = C.at(x);
      auto& ss = (x % 2 == 0) ? even : odd;
      auto& shift = (x % 2 == 0) ? evenShift : oddShift;
      if (p - shift >= a) {
	ss.erase(p);
	ss.insert(p - a);
	C.at(x) = p - a;
	ans += a;
	DLOG("*sell*", a);
      }else {
	DLOG("*skip*");
      }
    }
    if (t == 2) {
      ll a; cin >> a;
      DLOG("*IN*", 2, a);
      auto it = odd.begin();
      if (*it - oddShift >= a) {
	oddShift += a;
	ans += ((N + 1) / 2) * a;
	DLOG("*sell*", a);
      }else {
	DLOG("*skip*");
      }
    }
    if (t == 3) {
      ll a; cin >> a;
      DLOG("*IN*", 3, a);
      auto itO = odd.begin();
      ll minO = *itO;
      ll minE;
      if (even.empty()) {
	minE = LLONG_MAX;
      }else {
	auto itE = even.begin();
	minE = *itE;
      }
      if ((minO - oddShift >= a) && (minE - evenShift >= a)) {
	oddShift += a;
	evenShift += a;
	ans += N * a;
	DLOG("*sell*", a);
      }else {
	DLOG("*skip*");
      }
    }
  }
  cout << ans << endl;

  return 0;
}

