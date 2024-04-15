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

  auto func = [&](const auto& vec, ll goal) -> bool {
    ll lim = 1e4 + 10;
    ll n = ssize(vec);
    vector tbl_init(2 * lim, false);
    auto tbl = tbl_init;
    tbl[lim] = true;
    REP(i, 0, n) {
      auto prev = move(tbl);
      tbl = tbl_init;
      REP(j, 0, 2 * lim) {
        if (prev[j]) tbl[j - vec[i]] = tbl[j + vec[i]] = true;
      }
    }
    return tbl[lim + goal];
  };

  ll N; cin >> N;
  ll X, Y; cin >> X >> Y;
  // @InpVec(N, A) [vwfKMNFM]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [vwfKMNFM]

  vector<ll> vec1, vec2;
  REP(i, 1, N) {
    if (i % 2 == 0) vec1.push_back(A[i]);
    else vec2.push_back(A[i]);
  }
  bool b1 = func(vec1, X - A[0]);
  bool b2 = func(vec2, Y);
  cout << ((b1 and b2) ? "Yes" : "No") << endl;

  return 0;
}

