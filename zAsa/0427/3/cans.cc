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
  map<ll, ll> mp;
  REP(i, 0, N) {
    ll a; cin >> a;
    mp[a]++;
  }
  vector<ll> vec;
  for (auto [a, n] : mp) {
    if (n >= 2) vec.push_back(a);
  }
  ranges::sort(vec, greater<ll>());
  ll ans;
  if (ssize(vec) == 0) ans = 0;
  else if (ssize(vec) == 1) {
    ll a = vec[0];
    if (mp[a] >= 4) ans = a * a;
    else ans = 0;
  }else {
    ll a = vec[0], b = vec[1];
    if (mp[a] >= 4) ans = a * a;
    else ans = a * b;
  }
  cout << ans << endl;
  return 0;
}

