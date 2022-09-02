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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    // @InpVec(N, A) [tvjZsKhE]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [tvjZsKhE]
    // @InpVec(N, B) [xvE1jBJy]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [xvE1jBJy]
    vector<vector<ll>> CA, CB;
    CA.push_back(move(A));
    CB.push_back(move(B));
    ll ans = 0;
    REPrev(i, 30, 0) {
      auto NA = vector<vector<ll>>();
      auto NB = vector<vector<ll>>();
      bool fail = false;
      REP(j, 0, SIZE(CA)) {
        auto& vA = CA[j];
        auto& vB = CB[j];
        vector<ll> vA0, vA1, vB0, vB1;
        for (ll x : vA) {
          if (x >> i & 1) vA1.push_back(x);
          else vA0.push_back(x);
        }
        for (ll x : vB) {
          if (x >> i & 1) vB1.push_back(x);
          else vB0.push_back(x);
        }
        if (SIZE(vA1) == SIZE(vB0)) {
          assert(SIZE(vA0) == SIZE(vB1));
          if (SIZE(vA1) > 0) {
            NA.push_back(move(vA1));
            NB.push_back(move(vB0));
          }
          if (SIZE(vA0) > 0) {
            NA.push_back(move(vA0));
            NB.push_back(move(vB1));
          }
        }else {
          fail = true;
          break;
        }
      }
      if (fail) continue;
      CA = move(NA);
      CB = move(NB);
      ans |= (1LL << i);
    }
    return ans;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

