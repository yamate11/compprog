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
  // @InpVec(N, A) [xEvs4TVW]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [xEvs4TVW]
  
  ll tot = accumulate(ALL(A), 0LL);
  ll vmax = tot / 2;
  
  ll wmax = 2e5 + 1;
  vector<ll> cnt(wmax);
  REP(i, 0, N) cnt[A[i]]++;
  vector tbl(vmax + 1, false);
  tbl[0] = true;
  REP(w, 0, wmax) {
    ll x = cnt[w];
    if (x > 0) {
      vector<ll> vec;
      REP(k, 0, 21) {
        ll y = 1LL << k;
        if (x >= y) {
          vec.push_back(w * y);
          x -= y;
        }else {
          vec.push_back(w * x);
          break;
        }
      }
      for (ll v : vec) {
        REPrev(j, vmax, 0) {
          if (tbl[j] and j + v <= vmax) tbl[j + v] = true;
        }
      }
    }
  }
  REPrev(j, vmax, 0) if (tbl[j]) {
    cout << j << "\n";
    return 0;
  }
  return 0;
}

