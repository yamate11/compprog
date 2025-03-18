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

  ll N, M; cin >> N >> M;
  using sta = tuple<ll, ll, ll>;
  vector<sta> PYI;
  REP(i, 0, M) {
    ll p, y; cin >> p >> y;
    PYI.emplace_back(p, y, i);
  }
  sort(ALL(PYI));
  auto pad = [&](ll x) -> string {
    string a = to_string(x);
    string ret(6, '0');
    REP(i, 0, ssize(a)) ret[6 - ssize(a) + i] = a[i];
    return ret;
  };
  vector<string> ans(M);
  ll seq = 0;
  REP(j, 0, M) {
    auto [p, y, i] = PYI[j];
    if (j == 0 or get<0>(PYI[j - 1]) != p) seq = 1;
    ans[i] = pad(p) + pad(seq);
    seq++;
  }
  REPOUT(i, 0, M, ans[i], "\n");

  return 0;
}

