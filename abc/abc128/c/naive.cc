#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// See debug.cc for usage etc
#define DEBUG 1

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

ll N, M;
vector<vector <ll>> switches;
vector<ll> p;
vector<ll> com;

bool next_com() {
  for (ll i = 0; i < N; i++) {
    if (com.at(i) == 0) {
      com.at(i) = 1;
      return true;
    }else {
      com.at(i) = 0;
    }
  }
  return false;
}

bool check_one(ll mod, vector<ll> sw) {
  ll cnt = 0;
  for (ll j : sw) {
    cnt += com.at(j-1);
  }
  return cnt % 2 == mod;
}

bool check() {
  for (ll i = 0; i < M; i++) {
    if (!check_one(p.at(i), switches.at(i)))  return false;
  }
  return true;
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> M;
  switches.resize(M);
  for (ll i = 0; i < M; i++) {
    ll k;
    cin >> k;
    switches.at(i).resize(k);
    for (ll j = 0; j < k; j++) {
      cin >> switches.at(i).at(j);
    }
  }
  p.resize(M);
  for (ll i = 0; i < M; i++) {
    cin >> p.at(i);
  }
  ll answer = 0;
  com.resize(N);
  while (1) {
    if (check()) { answer++; }
    if (!next_com()) break;
  }
  cout << answer << endl;

  return 0;
}

