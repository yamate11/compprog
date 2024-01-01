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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

// @DefStruct(sta, (a, (b, string))) [JpBOp3va]
struct sta_t {
  ll a;
  string b;
  // sta_t() {}
  sta_t(ll a_ = ll(), string b_ = string()) : a(a_), b(b_) {}
  friend istream& operator>>(istream& istr, sta_t& t) {
    istr >> t.a >> t.b;
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const sta_t& t) {
    ostr << "(" << t.a << ", " << t.b << ")";
    return ostr;
  }
};
// @End [JpBOp3va]

int main(/* int argc, char *argv[] */) {
  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, read=(x, y)) [jXeAtqvA]
  struct nbr_t {
    int nd;
    ll x;
    ll y;
    // nbr_t() {}
    nbr_t(int nd_ = int(), ll x_ = ll(), ll y_ = ll()) : nd(nd_), x(x_), y(y_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;  
    ll x; cin >> x;
    ll y; cin >> y;
    nbr[u].emplace_back(v, x, y);
    nbr[v].emplace_back(u, x, y);
  }
  // @End [jXeAtqvA]
  
  auto f = [&](string x) -> int { return 0; };

}
