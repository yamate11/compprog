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

  ll x; cin >> x;

  vector<ll> vec;
  auto f = [&](ll a, ll d) -> void {
    ll digit = a;
    ll cur = digit;
    vec.push_back(cur);
    while (true) {
      if (cur > (ll)(2e17)) return;
      digit += d;
      if (not (0 <= digit and digit <= 9)) return;
      cur = 10 * cur + digit;
      vec.push_back(cur);
    }
  };
  REP(a, 1, 10) REP(d, -a, 10) f(a, d);
  sort(ALL(vec));
  auto it = lower_bound(ALL(vec), x);
  cout << *it << endl;

  return 0;
}

