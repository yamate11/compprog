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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector dist(N, vector(N, 0LL));
  using sta = tuple<ll, ll, ll>;
  vector<sta> adist;
  REP(i, 0, N - 1) {
    REP(j, i + 1, N) {
      ll a; cin >> a;
      dist[i][j] = dist[j][i] = a;
      adist.emplace_back(a, i, j);
    }
  }
  ranges::sort(adist, greater<sta>());
  vector order(N, vector<pll>());
  REP(i, 0, N) {
    REP(j, 0, N) if (j != i) {
      order[i].emplace_back(dist[i][j], j);
    }
    ranges::sort(order[i]);
  }
  
  ll numEff = N;
  vector<bool> eff(N, true);
  // vector<pll> edges;
  auto myget = [&](ll x) -> ll {
    for (auto [_d, i] : order[x]) {
      if (eff[i]) return i;
    }
    assert(0);
  };
  vector<pll> tot_ord;
  vector<ll> eff2;
  for (auto [a, i, j] : adist) {
    if (eff[i] and eff[j]) {
      if (numEff == 2) {
        // edges.emplace_back(i, j);
        eff2.push_back(i);
        eff2.push_back(j);
      }else {
        ll ki = myget(i);
        ll kj = myget(j);
        // edges.emplace_back(ki, i);
        // edges.emplace_back(kj, j);
        tot_ord.emplace_back(i, ki);
        tot_ord.emplace_back(j, kj);
        if (numEff == 3) {
          assert(ki == kj);
          eff2.push_back(ki);
        }
      }
      eff[i] = eff[j] = false;
      numEff -= 2;
    }
  }
  
  while (not tot_ord.empty()) {
    auto [i, k] = tot_ord.back(); tot_ord.pop_back();
    for (ll x : eff2) {
      if (dist[i][x] != dist[i][k] + dist[k][x]) {
        cout << "No\n";
        return 0;
      }
    }
    eff2.push_back(i);
  }
  cout << "Yes\n";

  return 0;
}

