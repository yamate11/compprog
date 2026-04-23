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

  ll N, K; cin >> N >> K;
  // @InpGrid(N, K, A) [r562P8l9]
  auto A = vector(N, vector(K, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < K; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [r562P8l9]
  vector chosen(1000000, false);
  ll p = K / N;
  ll q = K % N;
  REP(i, 0, N) {
    vector<ll> rep;
    vector<ll> cands;
    ll m = p + (i < q ? 1 : 0);
    for (ll j = 0; j < m; j++) cands.push_back(A[i][j]);
    while (not cands.empty()) {
      ll a = cands.back(); cands.pop_back(); 
      if (chosen[a]) {
        if (q <= i) cands.push_back(A[q][p]);
        if (++q == N) { p++; q = 0; }
      }else {
        chosen[a] = true;
        rep.push_back(a);
      }
    }
    ranges::sort(rep);
    REPOUT(j, 0, ssize(rep), rep[j], " ");
  }


  return 0;
}

