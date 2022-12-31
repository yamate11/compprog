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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll sz = 1LL << N;
  // @InpVec(sz, A) [dGPZYthi]
  auto A = vector(sz, ll());
  for (int i = 0; i < sz; i++) { ll v; cin >> v; A[i] = v; }
  // @End [dGPZYthi]
  vector<ll> cur(sz);
  iota(ALL(cur), 0);
  REP(j, 0, N - 1) {
    auto prev = move(cur);
    cur = vector<ll>();
    REP(i, 0, SIZE(prev) / 2) {
      if (A[prev[2 * i]] > A[prev[2 * i + 1]]) {
        cur.push_back(prev[2 * i]);
      }else {
        cur.push_back(prev[2 * i + 1]);
      }
    }
  }
  assert(SIZE(cur) == 2);
  ll a = cur[0];
  ll b = cur[1];
  if (A[a] > A[b]) cout << b + 1 << endl;
  else cout << a + 1 << endl;

  return 0;
}

