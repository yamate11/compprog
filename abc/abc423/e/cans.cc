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

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [8GNSo7Za]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [8GNSo7Za]

  vector<ll> vec0(N + 1);
  vector<ll> vec1(N + 1);
  vector<ll> vec2(N + 1);

  REP(i, 0, N) {
    vec0[i + 1] = vec0[i] + A[i];
    vec1[i + 1] = vec1[i] + i * A[i];
    vec2[i + 1] = vec2[i] + i * i * A[i];
  }

  REP(_q, 0, Q) {
    ll L, R; cin >> L >> R; L--; R--;
    ll val = - (vec2[R + 1] - vec2[L]) + (L + R) * (vec1[R + 1] - vec1[L]) - (L - 1) * (R + 1) * (vec0[R + 1] - vec0[L]);
    cout << val << "\n";
    
  }


  return 0;
}

