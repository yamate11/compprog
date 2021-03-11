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

  ll N; cin >> N;
  vector<vector<int>> nc(10, vector<int>(10));

  auto cntIJ = [&](ll i, ll j) -> ll {
    ll k = 0;
    for (ll base = 1; true; base *= 10) {
      ll x = ((i+1) * base - 1) * 10 + j;
      if (N < x) {
	for (ll p = 0; p < base; p++) {
	  if ((i * base + p) * 10 + j > N) {
	    DLOG("cntIJ", i, j, k);
	    return k;
	  }
	  k++;
	}
      }
      k += base;
    }
  };

  auto cntI = [&](ll i) -> ll {
    ll x;
    if (N < i) x = 0;
    else       x = cntIJ(i,i) + 1;
    DLOG("cntI", i, x);
    return x;
  };

  for (ll i = 1; i <= 9; i++) {
    for (ll j = 1; j <= 9; j++) {
      if (i == j) {
	nc.at(i).at(i) = cntI(i);
      }else {
	nc.at(i).at(j) = cntIJ(i, j);
      }
    }
  }


  ll cnt = 0;
  for (ll i = 1; i <= 9; i++) {
    for (ll j = 1; j <= 9; j++) {
      cnt += nc.at(i).at(j) * nc.at(j).at(i);
    }
  }
  cout << cnt << endl;

  return 0;
}

