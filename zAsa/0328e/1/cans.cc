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

  ll N, M; cin >> N >> M;
  // @InpVec(2*N, A) [As55uIxl]
  auto A = vector(2*N, ll());
  for (int i = 0; i < 2*N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [As55uIxl]
  map<ll, ll> mp;
  REP(i, 0, 2*N) mp[A[i]]++;
  set<ll> ss;
  for (auto [x, n] : mp) if (n % 2 == 1) ss.insert(x);
  ll n_good = 0, n_bad = 0;
  for (ll i : ss) {
    if (M % 2 == 0 and (ss.find((i + M/2) % M) != ss.end())) n_good++;
    else n_bad++;
  }
  if (n_bad == 0 and n_good % 4 == 0) cout << "Bob\n";
  else cout << "Alice\n";

  return 0;
}

