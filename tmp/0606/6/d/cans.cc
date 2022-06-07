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

  using pll = pair<ll, ll>;
  ll N; cin >> N;
  auto func = [&](auto& V) -> vector<ll> {
    const ll big = 1e10;
    vector<ll> ret(N);
    vector<pll> stack;
    stack.emplace_back(big, 0);
    REP(i, N) {
      ll cnt = 0;
      while (true) {
        auto [h, n] = stack.back();
        if (h > V[i]) break;
        cnt += n;
        stack.pop_back();
      }
      ret[i] = cnt;
      stack.emplace_back(V[i], cnt + 1);
    }
    return ret;
  };
  vector<ll> H(N); REP(i, N) cin >> H[i];
  auto R = H;
  reverse(ALL(R));
  auto vec1 = func(H);
  auto vec2 = func(R);
  reverse(ALL(vec2));
  REP(i, N) cout << vec1[i] + vec2[i] << "\n";

  return 0;
}

