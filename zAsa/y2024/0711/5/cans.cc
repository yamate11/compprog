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

  ll N, D; cin >> N >> D;
  if (2 * D > N - 1) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  vector<pll> ans;
  REP(i, 0, D) {
    ll step = i + 1;
    ll g = gcd(N, step);
    REP(j, 0, g) {
      REP(k, 0, N / g) {
        ans.emplace_back((j + k * step) % N, (j + (k + 1) * step) % N);
      }
    }
  }
  for (auto [x, y] : ans) {
    cout << x + 1 << " " << y + 1 << "\n";
  }

  return 0;
}

