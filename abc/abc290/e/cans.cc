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
  // @InpVec(N, A, dec=1) [rIksFaWw]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [rIksFaWw]
  vector P(N, vector<ll>());
  REP(i, 0, N) P[A[i]].push_back(i);
  ll tot = 0;
  REP(k, 1, N + 1) tot += (k / 2) * (N - k + 1);
  ll vvv = 0;
  REP(c, 0, N) {
    auto& vec = P[c];
    ll M = ssize(vec);
    if (M <= 1) continue;
    vector S(M, 0LL);
    S[0] = vec[0] + 1;
    REP(i, 1, M) S[i] = S[i - 1] + vec[i] + 1;
    ll vv = 0;
    REPrev(j, M - 1, 0) {
      ll p = lower_bound(ALL(vec), N - vec[j] - 1) - vec.begin();
      if (p == N) p = N - 1;
      else if (vec[p] > N - vec[j] - 1) p--;
      ll val;
      if (p >= j) p = j - 1;
      if (p < 0) val = 0;
      else val = S[p];
      val += (j - p - 1) * (N - vec[j]);
      vv += val;
    }
    vvv += vv;
  }
  cout << tot - vvv << endl;

  return 0;
}

