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

  ll N; cin >> N;
  // // @InpMVec(N, ((S, type=string), T)) [cUTBPpA9]
  // auto S = vector(N, string());
  // auto T = vector(N, ll());
  // for (int i = 0; i < N; i++) {
  //   string v1; cin >> v1; S[i] = v1;
  //   ll v2; cin >> v2; T[i] = v2;
  // }
  // // @End [cUTBPpA9]

  string s0; cin >> s0;
  ll t0; cin >> t0;

  ll ans = 0;
  ll vmax = t0;
  set<string> ss;
  ss.insert(s0);
  REP(i, 1, N) {
    string s; cin >> s;
    ll t; cin >> t;
    if (ss.contains(s)) {
      ;
    }else {
      ss.insert(s);
      if (vmax < t) {
        vmax = t;
        ans = i;
      }
    }
  }
  cout << ans + 1 << endl;

  return 0;
}

