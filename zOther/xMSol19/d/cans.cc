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
vector<set<int>> nbr;
vector<ll> c;
vector<ll> d;
int idx;

void operate(int n) {
  if (nbr.at(n).size() != 1)  return;
  auto it = nbr.at(n).begin();
  int r = *it;
  d.at(n) = c.at(idx++);
  nbr.at(n).erase(it);
  nbr.at(r).erase(n);
  if (nbr.at(r).size() == 0) {
    d.at(r) = c.at(idx++);
  }else {
    operate(r);
  }
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  nbr.resize(N+1);
  c.resize(N);
  d.resize(N+1);
  for (int i = 0; i < N-1; i++) {
    int a, b;
    cin >> a >> b;
    nbr.at(a).insert(b);
    nbr.at(b).insert(a);
  }
  ll M = 0;
  for (int i = 0; i < N; i++) {
    cin >> c.at(i);
    M += c.at(i);
  }
  sort(c.begin(), c.end());
  M -= c.at(N-1);

  for (int i = 1; i <= N; i++) {
    operate(i);
  }
  cout << M << "\n";
  for (int i = 1; i <= N; i++) {
    if (i > 1)  cout << " ";
    cout << d.at(i);
  }
  cout << endl;

  return 0;
}

