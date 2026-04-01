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
  // @InpVec(N, S, type=string) [reGl0L3z]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [reGl0L3z]

  ll n_alph = 26;
  vector<ll> vec(n_alph);
  REP(i, 0, n_alph) vec[i] = i;
  REP(_q, 0, Q) {
    char c1, c2; cin >> c1 >> c2;
    ll d1 = c1 - 'a';
    ll d2 = c2 - 'a';
    REP(i, 0, n_alph) if (vec[i] == d1) vec[i] = d2;
  }
  REP(i, 0, N) {
    REP(j, 0, ssize(S[i])) S[i][j] = vec[S[i][j] - 'a'] + 'a';
    cout << S[i] << "\n";
  }

  return 0;
}

