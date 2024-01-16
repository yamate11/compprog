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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, D; cin >> N >> D;
  vector<pll> RL;
  REP(i, 0, N) {
    ll l, r; cin >> l >> r;
    RL.emplace_back(r, l);
  }
  sort(ALL(RL));
  ll cnt = 0;
  for (ll i = 0; i < N;) {
    cnt++;
    ll lim = RL[i].first;
    for (i++; i < N and RL[i].second <= lim + D - 1; i++);
  }
  cout << cnt << endl;
  return 0;
}

