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

  ll N, V; cin >> N >> V;
  // @InpVec(N - 1, D) [wraJZeKM]
  auto D = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; D[i] = v; }
  // @End [wraJZeKM]
  // @InpVec(N - 1, T) [3AO1flX7]
  auto T = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; T[i] = v; }
  // @End [3AO1flX7]

  vector<ll> S(N);
  REP(i, 0, N - 1) S[i + 1] = S[i] + D[i];
  vector<ll> ans;
  REP(i, 1, N) {
    if (S[i] / V < T[i - 1]) ans.push_back(i + 1);
  }
  if (ssize(ans) == 0) {
    cout << -1 << endl;
  }else {
    REPOUT(i, 0, ssize(ans), ans[i], " ");
  }

  return 0;
}

