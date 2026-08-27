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

  auto solve = [&]() -> void {
    ll N, Q; cin >> N >> Q;
    string s, t; cin >> s >> t;
    vector<ll> A01(N + 1);
    vector<ll> A10(N + 1);
    vector<ll> Aaa(N + 1);
    REP(i, 0, N) {
      A01[i + 1] = A01[i];
      A10[i + 1] = A10[i];
      Aaa[i + 1] = Aaa[i];
      if      (s[i] == '0' and t[i] == '1') A01[i + 1]++;
      else if (s[i] == '1' and t[i] == '0') A10[i + 1]++;
      else                                  Aaa[i + 1]++;
    }
    REP(_q, 0, Q) {
      ll l, r; cin >> l >> r; l--;
      ll e01 = A01[r] - A01[l];
      ll e10 = A10[r] - A10[l];
      ll eaa = Aaa[r] - Aaa[l];
      if (abs(e01 - e10) <= eaa) {
        cout << "YES\n";
      }else {
        cout << "NO\n";
      }
    }

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

