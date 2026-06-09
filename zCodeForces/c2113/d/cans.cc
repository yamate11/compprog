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

  auto solve = [&]() -> void {
    ll n; cin >> n;
    // @InpVec(n, A) [NTvQ09lM]
    auto A = vector(n, ll());
    for (int i = 0; i < n; i++) { ll v; cin >> v; A[i] = v; }
    // @End [NTvQ09lM]
    // @InpVec(n, B) [zOOoyK1r]
    auto B = vector(n, ll());
    for (int i = 0; i < n; i++) { ll v; cin >> v; B[i] = v; }
    // @End [zOOoyK1r]

    ll a = 0, b = 0;
    ll wa = 0, wb = 0;
    ll last_a = -1, corr_b = -1;
    REP(i, 0, n) {
      if (A[a] < B[b]) {
        last_a = a;
        corr_b = b;
        wb++;
        b++;
      }else {
        wa++;
        a++;
      }
    }
    ll wa0 = wa;
    if (last_a >= 0) {
      ll j = n - 1;
      bool found = false;
      for ( ; j > last_a; j--) {
        if (B[corr_b] < A[j]) {
          found = true;
          break;
        }
      }
      if (found) {
        swap(A[last_a], A[j]);
        ll a2 = 0, b2 = 0;
        ll wa2 = 0;
        REP(i, 0, n) {
          if (A[a2] < B[b2]) {
            b2++;
          }else {
            a2++;
            wa2++;
          }
        }
        wa0 = max(wa0, wa2);
      }
    }
    cout << wa0 << "\n";


  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

