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

ll N, K;
vector<ll> V;

string toString(auto v) {
  stringstream ss;
  ss << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin())  ss << ", ";
    // if the value_type is not printable, modify the following line.
    ss << *it;
    // e.g., if it is a pair, use "ss << pairToString(*it)"
  }
  ss << "]";
  return ss.str();
}



int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> K;
  V.resize(N);
  for (ll i = 0; i < N; i++) {
    cin >> V.at(i);
  }
  ll answer = 0;
  for (ll y = 0; y <= min(N, K); y++) {
    for (ll a = 0; a <= y; a++) {
      ll b = y - a;
      vector<ll> w(y);
      copy(V.begin(), V.begin() + a, w.begin());
      copy(V.end() - b, V.end(), w.begin() + a);
      DLOG("w = %s", toString(w).c_str());
      sort(w.begin(), w.end());
      ll sum = 0;
      for (ll k = 0; k < y; k++) {
	if (k >= K-y || w.at(k) > 0)  sum += w.at(k);
      }
      DLOG("(a,b) = (%lld, %lld), sum = %lld", a, b, sum);
      if (sum > answer)  answer = sum;
    }
  }
  cout << answer << endl;

  return 0;
}

