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

  ll N; cin >> N;
  // @InpMVec(N, (X, Y)) [j697HZHn]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [j697HZHn]
  string S; cin >> S;
  map<ll, vector<pll>> mp;
  REP(i, 0, N) {
    mp[Y[i]].emplace_back(X[i], S[i] == 'R' ? 1 : -1);
  }
  for (auto& [y, vec] : mp) {
    bool right = false;
    sort(ALL(vec));
    for (auto [x, d] : vec) {
      if (d > 0) right = true;
      else if (right) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";

  return 0;
}

