#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// See debug.cc for usage etc
#define DEBUG 0

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#if DEBUG
  #define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DCALL(func, ...)
#endif

ll N, Q;
string S;
vector<ll> acc;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> Q >> S;
  acc.resize(N);
  acc.at(0) = 0;
  ll cnt = 0;
  for (ll i = 0; i < N - 1; i++) {
    if (S.at(i) == 'A' && S.at(i+1) == 'C') {
      cnt++;
    }
    acc.at(i+1) = cnt;
  }
  for (ll i = 0; i < Q; i++) {
    ll l, r;
    cin >> l;
    cin >> r;
    cout << acc.at(r-1) - acc.at(l-1) << "\n";
  }
  return 0;
}
