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
  multiset<ll> ss;
  REP(i, 0, N) {
    ll a; cin >> a;
    ss.insert(a);
  }
  ll ans = 0;
  while (ss.size() > 1) {
    ans++;
    auto it1 = ss.begin();
    auto it2 = ss.end(); it2--;
    ll t = *it2 % *it1;
    ss.erase(it2);
    if (t > 0) ss.insert(t);
  }
  cout << ans << endl;

  return 0;
}

