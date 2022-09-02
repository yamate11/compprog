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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;
  string alph = "ABXY";
  ll ans = 1e9;
  REP(i, 0, 4) REP(j, 0, 4) REP(k, 0, 4) REP(l, 0, 4) {
    ll cnt = 0;
    ll x = 0;
    while (x < N) {
      if (x < N - 1 and (   (S[x] == alph[i] and S[x + 1] == alph[j])
                            or (S[x] == alph[k] and S[x + 1] == alph[l]))) {
        x += 2;
      }else {
        x++;
      }
      cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}

