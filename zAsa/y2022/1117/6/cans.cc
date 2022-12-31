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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [4xKKBeRH]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [4xKKBeRH]
  auto B = A;
  REP(i, 0, N) B.push_back(A[i]);
  ll lim = 2e5;
  vector<ll> pos(lim + 1, -1);
  vector<ll> C(N);
  REPrev(i, 2*N - 1, 0) {
    if (i < N) C[i] = pos[A[i]] + 1;
    pos[B[i]] = i;
  }
  auto f = [&](ll z) -> tuple<bool, ll, vector<ll>> {
    ll x = 0;
    ll c = 0;
    while (true) {
      if (c == 0 and x > 0) return {false, x, {}};
      ll y = C[c];
      if (x + (y / N) >= z) {
        if (x + (y / N) == z and y == N) return {true, -1, {}};
        vector<ll> ret;
        while (c < N) {
          if (C[c] <= N) c = C[c];
          else {
            ret.push_back(A[c]);
            c++;
          }
        }
        return {true, -1, move(ret)};
      }else {
        c = y % N;
        x += y / N;
      }
    }
  };
  auto [b, x, v] = f(K);
  if (b) {
    REPOUT(i, 0, SIZE(v), v[i], " ");
    return 0;
  }
  auto [bb, xx, vv] = f(K % x);
  assert(bb);
  REPOUT(i, 0, SIZE(vv), vv[i], " ");

  return 0;
}

