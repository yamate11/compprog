#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string N; cin >> N;
  ll sz = SIZE(N);
  ll ans = 0;
  auto check = [&](ll x) -> ll {
    string a = "";
    string b = "";
    for (ll i = 0; i < sz; i++) {
      if (x & (1LL << i)) a += N[i];
      else b += N[i];
    }
    sort(ALL(a), greater<char>());
    sort(ALL(b), greater<char>());
    if (a[0] == '0' || b[0] == '0') return 0;
    return stoll(a) * stoll(b);
  };
  for (ll x = 1; x < (1LL << sz) - 1; x++) {
    ll y = check(x);
    ans = max(ans, y);
  }
  cout << ans << endl;

  return 0;
}

