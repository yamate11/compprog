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

  ll L, R; cin >> L >> R;
  if (L == 0) {
    vector<ll> ans;
    ans.push_back(L);
    REPrev(k, 60, 0) {
      if (R >> k & 1) {
        L |= (1LL << k);
        ans.push_back(L);
      }
    }
    cout << ssize(ans) - 1 << endl;
    REP(i, 0, ssize(ans) - 1) {
      cout << ans[i] << " " << ans[i + 1] << "\n";
    }
    return 0;
  }

  ll k = 60;
  while (not (not (L >> k & 1) and (R >> k & 1))) k--;
  ll k0 = k;

  vector<ll> ans;
  ans.push_back(L);
  k = 0;
  while (true) {
    while (not (L >> k & 1) and k < k0) k++;
    if (k == k0) break;
    ll t = 1LL << k;
    L += t;
    ans.push_back(L);
    k++;
  }
  // ans.push_back(L);
  for (k--; k >= 0; k--) {
    if (R >> k & 1) {
      L |= (1LL << k);
      ans.push_back(L);
    }
  }
  cout << ssize(ans) - 1 << endl;
  REP(i, 0, ssize(ans) - 1) {
    cout << ans[i] << " " << ans[i + 1] << "\n";
  }


  return 0;
}

