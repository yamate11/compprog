#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector child(N, vector<ll>());
  vector parent(N, -1LL);
  REP2(i, 1, N) {
    ll a; cin >> a; a--;
    parent[i] = a;
    child[a].push_back(i);
  }
  auto dfs = [&](auto rF, ll nd, ll pt) -> ll {
    vector<ll> tmp;
    for (ll cld : child[nd]) {
      ll d = rF(rF, cld, nd);
      tmp.push_back(d);
    }
    if (tmp.empty()) return 0;
    sort(ALL(tmp));
    ll cur = 0;
    for (ll d : tmp) {
      cur = 1 + max(cur, d);
    }
    return cur;
  };
  ll a = dfs(dfs, 0, -1);
  cout << a << endl;
  return 0;
}

