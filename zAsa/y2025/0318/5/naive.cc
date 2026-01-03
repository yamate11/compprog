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

using sta = pair<bool, string>;

sta cond(ll n) {
  ll p = llround(floor(sqrt(n)));
  string sn = to_string(n);
  string sp = to_string(p);
  if (sn.substr(0, ssize(sp)) == sp) {
    return sta(true, sp);
  }else {
    return sta(false, "");
  }
}


void test() {
  set<string> ss;
  REP(i, 1, 100000000) {
    auto [b, sp] = cond(i);
    if (b) ss.insert(sp);
  }
  for (string s : ss) cout << s << "\n";
}


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  // test();

  vector<ll> pow10(19);
  pow10[0] = 1;
  REP(i, 1, 19) pow10[i] = 10 * pow10[i - 1];
  vector<ll> v_full(19);
  v_full[0] = 0;
  for (ll k = 2; k <= 18; k++) {
    ll x = pow10[k / 2 - 1];
    v_full[k] = v_full[k - 2] + 1 + x + 10 * x;
  }

  auto powc = [&](ll n) -> ll {
    ll k = 0;
    while (true) {
      if (k == 20) return 20;
      if (n < pow10[k]) return k;
      k += 2;
    }
  };

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    ll k = powc(N) - 2;
    if (k == 18) return v_full[18] + 1;
    ll ans = v_full[k];
    if (N < pow10[k] + pow10[k / 2]) {
      return ans + N - pow10[k] + 1;
    }
    ans += pow10[k / 2];
    ll z8 = pow10[k + 2] - 20 * pow10[k / 2];
    if (N < z8) return ans;
    ans++;
    ll z9 = pow10[k + 2] - 10 * pow10[k / 2];
    if (N < z9) return ans;
    return ans + N - z9 + 1;
  };


  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << endl;

  return 0;
}

