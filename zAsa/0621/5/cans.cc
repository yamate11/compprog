#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

void r_move(ll nd) {
  cout << nd + 1 << endl;
}

vector<ll> nbr() {
  ll k; cin >> k;
  // @InpVec(k, ret, dec=1) [vQOMdoVR]
  auto ret = vector(k, ll());
  for (int i = 0; i < k; i++) { ll v; cin >> v; v -= 1; ret[i] = v; }
  // @End [vQOMdoVR]
  return ret;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector visited(N, false);

  auto dfs = [&](auto rF, ll nd) -> bool {
    if (visited[nd]) return false;
    if (nd != 0) r_move(nd);
    if (nd == N - 1) {
      string s; cin >> s;
      exit(0);
    }
    visited[nd] = true;
    auto vnb = nbr();
    for (ll c : vnb) {
      bool b = rF(rF, c);
      if (b) {
        r_move(nd);
        nbr();
      }
    }
    return true;
  };

  dfs(dfs, 0);

  return 0;
}

