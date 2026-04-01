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

  ll N, L; cin >> N >> L;
  map<ll, ll> mp;
  mp[0] = 0;
  mp[L] = 0;
  REP(i, 0, N) {
    ll x, r; cin >> x >> r;
    mp[x - r] += 1;
    mp[x + r] -= 1;
  }
  ll c = 0;
  for (auto [y, n] : mp) {
    c += n;
    if (y == L) break;
    if (y >= 0 and c == 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}

