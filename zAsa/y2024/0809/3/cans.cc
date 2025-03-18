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
  // @InpVec(N, A) [5x8xQRT9]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [5x8xQRT9]
  ll Q; cin >> Q;
  ll base = 0;
  vector<pll> hist;
  REP(i, 0, N) hist.emplace_back(i, A[i]);
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x;
      base = x;
      while (not hist.empty()) {
        auto [ii, xx] = hist.back(); hist.pop_back();
        A[ii] -= xx;
      }
    }else if (tp == 2) {
      ll i, x; cin >> i >> x; i--;
      A[i] += x;
      hist.emplace_back(i, x);
    }else if (tp == 3) {
      ll i; cin >> i; i--;
      cout << base + A[i] << "\n";
    }
  }

  return 0;
}

