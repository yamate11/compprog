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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

// @DefStruct(ev, (a, b, c)) [wJ4qpt9n]
struct ev_t {
  ll a;
  ll b;
  ll c;
  ev_t() {}
  ev_t(ll a_, ll b_, ll c_) : a(a_), b(b_), c(c_) {}
  friend istream& operator>>(istream& istr, ev_t& t) {
    istr >> t.a >> t.b >> t.c;
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const ev_t& t) {
    ostr << "(" << t.a << ", " << t.b << ", " << t.c << ")";
    return ostr;
  }
};
// @End [wJ4qpt9n]

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ev_t ev; cin >> ev;
  cout << ev << endl;

  struct foo {
    ll x;
    ll y;
  };
  int goo();
  foo f;
  f.x = 10;
  f.y = 20;
  

  return 0;
}
