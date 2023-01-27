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

  ll N, C; cin >> N >> C;
  // @InpMVec(N, (s, t, c)) [YSLw2bD4]
  auto s = vector(N, ll());
  auto t = vector(N, ll());
  auto c = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; s[i] = v1;
    ll v2; cin >> v2; t[i] = v2;
    ll v3; cin >> v3; c[i] = v3;
  }
  // @End [YSLw2bD4]
  enum {Begin, End};
  using ev_t = tuple<ll, ll, ll>;
  vector<ev_t> ev;
  REP(i, 0, N) {
    ev.emplace_back(s[i], Begin, c[i]);
    ev.emplace_back(t[i], End, c[i]);
  }
  sort(ALL(ev));
  vector<ll> rec(C + 1, false);
  ll ans = 0;
  ll cur = 0;
  for (auto [tm, tp, ch] : ev) {
    if (tp == Begin) {
      if (rec[ch] > 0) {
        rec[ch]++;
      }else {
        cur++;
        ans = max(ans, cur);
        rec[ch]++;
      }
    }else if (tp == End) {
      if (rec[ch] > 1) {
      }else {
        cur--;
      }
      rec[ch]--;
    }else assert(0);
  }
  cout << ans << endl;

  return 0;
}

