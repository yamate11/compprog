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

  vector<ll> x2{0, 1, 0, 0, 1, 1, 0, 1};
  vector<ll> x3{0, 0, 1, 0, 1, 2, 0, 2, 1, 1, 2, 2};

  auto solve = [&]() -> void {
    auto f = [&](ll z, ll s) {
      const auto& vec = z == 2 ? x2 : x3;
      for (ll d : vec) cout << s + d << " ";
    };

    ll N; cin >> N;
    if (N == 2) {
      f(2, 1);
    }else if (N == 3) {
      f(3, 1);
    }else {
      ll p = N / 2;
      ll q = N % 2;
      if (q == 1) p--;
      REP(i, 0, p) f(2, 1 + 2 * i);
      if (q == 1) f(3, 1 + 2 * p);
    }
    cout << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

