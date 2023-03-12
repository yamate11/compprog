#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, fwd, dir=True, dec=1) [XYB6y7TR]
  auto fwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
  }
  // @End [XYB6y7TR]
  ll t0 = 0;
  REP(s, 0, N) {
    vector<bool> rcbl(N, false);
    rcbl[s] = true;
    queue<ll> que;
    que.push(s);
    while (not que.empty()) {
      ll x = que.front(); que.pop();
      for (ll y : fwd[x]) {
        if (not rcbl[y]) {
          t0++;
          rcbl[y] = true;
          que.push(y);
        }
      }
    }
  }
  cout << t0 - M << endl;

  return 0;
}

