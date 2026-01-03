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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

// @DefStruct(info, (a, c), ord=(c)) [bbzRs4pv]
struct info_t {
  ll a;
  ll c;
  info_t(ll a_ = ll(), ll c_ = ll()) : a(a_), c(c_) {}
  friend istream& operator>>(istream& istr, info_t& t) {
    istr >> t.a >> t.c;
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const info_t& t) {
    ostr << "(" << t.a << ", " << t.c << ")";
    return ostr;
  }
  bool operator<(const info_t& o) const {
    if (c < o.c) return true;
    if (c > o.c) return false;
    return false;
  }
};
// @End [bbzRs4pv]

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpVec(M, info, type=info_t) [oeUVmFmS]
  auto info = vector(M, info_t());
  for (int i = 0; i < M; i++) { info_t v; cin >> v; info[i] = v; }
  // @End [oeUVmFmS]

  sort(ALL(info));
  ll n = N;
  ll ans = 0;
  for (auto [a, c] : info) {
    ll g = gcd(n, a);
    ll x = n / g;
    ans += g * c * (x - 1);
    n = g;
  }
  if (n > 1) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}

