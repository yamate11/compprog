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

  ll N, M; cin >> N >> M;
  // @InpMVec(M, (X, Y, (C, type=char))) [WOru8eBw]
  auto X = vector(M, ll());
  auto Y = vector(M, ll());
  auto C = vector(M, char());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
    char v3; cin >> v3; C[i] = v3;
  }
  // @End [WOru8eBw]

  using sta = tuple<ll, ll, ll>;
  vector<sta> vec;
  REP(i, 0, M) {
    vec.emplace_back(X[i], C[i] == 'B' ? 2 : 1, Y[i]);
  }
  sort(ALL(vec));
  ll lim = N + 1;
  for (auto [x, c, y] : vec) {
    if (c == 1) lim = min(lim, y);
    if (c == 2 and lim <= y) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  
  

  return 0;
}

