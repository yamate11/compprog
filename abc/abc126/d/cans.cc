#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
  #define DFUNC(fname, ...) fname(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFUNC(fname, ...)
#endif

ll N;
vector<vector <pair<ll, ll>>> nbr;
vector<ll> vColor;

void dfs(ll parent, ll node, ll color) {
  vColor.at(node) = color;
  for (auto p : nbr.at(node)) {
    if (p.first == parent) continue;
    if (p.second % 2 == 0) {
      dfs(node, p.first, color);
    }else {
      dfs(node, p.first, 1 - color);
    }
  }
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  nbr.resize(N+1);
  for (ll i = 1; i < N; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    nbr.at(u).push_back(make_pair(v, w));
    nbr.at(v).push_back(make_pair(u, w));
  }
  vColor.resize(N+1);
  dfs(-1, 1, 0);
  
  for (ll i = 1; i <= N; i++) {
    cout << vColor.at(i) << endl;
  }
  
  return 0;
}

