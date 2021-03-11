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

ll N;
constexpr ll maxN = 2e5;
vector<pair<ll, ll>> AB;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N;
  for (ll i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    AB.push_back(make_pair(b, a));
  }
  for (ll i = 0; i < N; i++) {
    DLOG("AB[%lld] = (%lld, %lld)", i, AB[i].first, AB[i].second);
  }
  sort(AB.begin(), AB.end());
  for (ll i = 0; i < N; i++) {
    DLOG("AB[%lld] = (%lld, %lld)", i, AB[i].first, AB[i].second);
  }
  ll t = 0;
  for (ll i = 0; i < N; i++) {
    t += AB[i].second;
    DLOG("t = %lld", t);
    if (t > AB[i].first) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}

