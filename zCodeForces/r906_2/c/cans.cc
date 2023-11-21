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
    ll N; cin >> N;
    string S; cin >> S;
    ll cnt0 = 0, cnt1 = 0;
    REP(i, 0, N) {
      if (S[i] == '0') cnt0++;
      else cnt1++;
    }
    if (cnt0 != cnt1) {
      cout << "-1\n";
      return;
    }
    vector<ll> ans;
    ll margin = 400;
    ll top = margin;
    ll p = top;
    ll q = top + N - 1;
    S = string(margin, ' ') + S + string(margin, ' ');
    while (p < q) {
      if (S[p] == '0' and S[q] == '0') {
        ans.push_back(q - top + 1);
        S[q + 1] = '0';
        q++;
        p++;
      }else if (S[p] == '1' and S[q] == '1') {
        ans.push_back(p - top);
        S[p - 1] = '1';
        p--;
        q--;
        top -= 2;
      }else if (S[p] != S[q]) {
        p++;
        q--;
      }else assert(0);
    }
    cout << SIZE(ans) << "\n";
    REPOUT(i, 0, SIZE(ans), ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

