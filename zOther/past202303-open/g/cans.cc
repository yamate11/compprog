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

  ll H, W; cin >> H >> W;
  vector A(H, vector(W, 0LL));
  REP(i, 0, H) REP(j, 0, W) {
    ll a; cin >> a;
    A[i][j] = a;
  }
  vector<pll> nbr;
  auto f = [&](ll a, ll b) -> void {
    if (a > b) swap(a, b);
    nbr.emplace_back(a, b);
  };

  REP(i, 0, H) REP(j, 0, W - 1) f(A[i][j], A[i][j + 1]);
  REP(i, 0, H - 1) REP(j, 0, W) f(A[i][j], A[i + 1][j]);
  sort(ALL(nbr));
  for (auto [a, b] : nbr) {
    cout << a << " " << b << "\n";
  }

  return 0;
}

