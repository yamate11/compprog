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

  string a, b; cin >> a >> b;
  vector<ll> ca(10), cb(10);
  REP(i, SIZE(a)) ca[a[i] - '0']++;
  REP(i, SIZE(b)) cb[b[i] - '0']++;
  ll match = 0;
  string ans_a = a;
  string ans_b = b;

  auto func = [&](ll d, ll e) -> void {
    using sta = pair<ll, ll>;
    vector<sta> va, vb;
    va.emplace_back(d, 1);
    vb.emplace_back(e, 1);
    vector<ll> xa = ca;
    vector<ll> xb = cb;
    xa[d]--;
    xb[e]--;
    ll m = 1;
    REP2(i, 1, 10) {
      REP2(j, 9 - i, 9) {
        ll k = min(xa[i], xb[j]);
        va.emplace_back(i, k);
        vb.emplace_back(j, k);
        xa[i] -= k;
        xb[j] -= k;
        m += k;
      }
    }
    REP2(i, 1, 10) {
      ll k = min(xa[i], xb[9]);
      va.emplace_back(i, k);
      vb.emplace_back(9, k);
      xa[i] -= k;
      xb[9] -= k;
      m += k;
    }
    if (xa[9] > 0) {
      m += xa[9];
      va.emplace_back(9, xa[9]);
      xa[9] = 0;
    }
    if (xb[9] > 0) {
      m += xb[9];
      vb.emplace_back(9, xb[9]);
      xb[9] = 0;
    }
    REP2(i, 1, 9) { va.emplace_back(i, xa[i]); }
    REP2(i, 1, 9) { vb.emplace_back(i, xb[i]); }
    if (match < m) {
      match = m;
      ans_a = "";
      ans_b = "";
      for (auto& [x, k] : va) REP(i, k) ans_a.push_back('0' + x);
      for (auto& [x, k] : vb) REP(i, k) ans_b.push_back('0' + x);
      reverse(ALL(ans_a));
      reverse(ALL(ans_b));
    }
  };

  REP2(d, 1, 10) {
    if (ca[d] == 0) continue;
    REP2(e, 10 - d, 10) {
      if (cb[e] > 0) {
        func(d, e);
        break;
      }
    }
  }
  cout << ans_a << endl;
  cout << ans_b << endl;

  return 0;
}

