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

  auto solve = [&]() -> void {
    ll N, K; cin >> N >> K;
    string S; cin >> S;
    if (K % 2 == 0) {

      vector<ll> even(26), odd(26);
      REP(i, 0, N) {
        ll d = S[i] - 'a';
        if (i % 2 == 0) even[d]++;
        else odd[d]++;
      }
      REP(d, 0, 26) {
        
      }

      

    }else {
      string a, b;
      REP(i, 0, N) {
        if (i % 2 == 0) a.push_back(S[i]);
        else b.push_back(S[i]);
      }
      sort(ALL(a));
      sort(ALL(b));
      string ans;
      REP(i, 0, N) {
        if (i % 2 == 0) ans.push_back(a[i / 2]);
        else ans.push_back(b[i / 2]);
      }
      cout << ans << endl;
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

