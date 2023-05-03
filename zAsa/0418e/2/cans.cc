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

using vll = vector<ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll one = 1;
  
  auto ask = [&](ll i, ll j, ll k) -> bool {
    cout << "? " << i << " " << j << " " << k << endl;
    string a; cin >> a;
    return a == "Yes";
  };

  auto msort = [&](auto rF, auto& vec, ll l, ll r) -> vll {
    if (r - l == 1) return vll{vec[l]};
    ll m = (l + r) / 2;
    auto v1 = rF(rF, vec, l, m);
    auto v2 = rF(rF, vec, m, r);
    ll sz1 = SIZE(v1);
    ll sz2 = SIZE(v2);
    vll ret;
    ll i = 0, j = 0;
    while (i < sz1 and j < sz2) {
      if (ask(v1[i], one, v2[j])) {
        ret.push_back(v2[j]);
        j++;
      }else {
        ret.push_back(v1[i]);
        i++;
      }
    }
    for (; i < sz1; i++) ret.push_back(v1[i]);
    for (; j < sz2; j++) ret.push_back(v2[j]);
    return ret;
  };

  REP(y, 2, N + 1) {
    if (ask(one, one, y)) one = y;
  }
  vector<ll> vec(N);
  REP(i, 0, N) vec[i] = i + 1;
  auto ss = msort(msort, vec, 0, N);
  assert(ss[0] == one);
  vector<ll> ans(N + 1);
  REP(i, 0, N) ans[ss[i]] = i + 1;
  cout << "!";
  REP(i, 1, N + 1) cout << " " << ans[i];
  cout << endl;


  return 0;
}

