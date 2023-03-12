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
  // @InpVec(N, A) [rdizjCUL]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [rdizjCUL]
  // @InpVec(N, B) [gqyCvyWT]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [gqyCvyWT]

  constexpr ll bsz = 500000;

  vector<ll> val(N);
  auto func = [&](ll k) -> void {
    bitset<bsz> bsA, bsB;
    REP(i, 0, N) bsA.set(i, A[i] >> k & 1);
    REP(i, 0, N) bsB.set(i, B[i] >> k & 1);
    REP(i, 0, N) {
      ll e = (bsA | bsB).count();
      val[i] += e << k;
      ll x = bsA.test(0);
      bsA >>= 1;
      bsA.set(N-1, x);
    }
  };
  REP(k, 0, 5) func(k);
  cout << *max_element(ALL(val)) << endl;

  return 0;
}

