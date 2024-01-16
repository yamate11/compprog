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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [udMaap7k]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [udMaap7k]
  map<ll, ll> mp;
  REP(i, 0, N) mp[-A[i]]++;
  ll f = -1;
  for (auto [x, c] : mp) {
    if (c == 1) continue;
    ll y = -x;
    if (f < 0) {
      if (c < 4) {
        f = y;
      }else {
        cout << y * y << endl;
        return 0;
      }
    }else {
      cout << f * y << endl;
      return 0;
    }
  }
  cout << 0 << endl;

  return 0;
}

