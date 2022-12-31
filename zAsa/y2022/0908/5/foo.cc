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

struct LLMax {
  ll v;
  LLMax() : v(LLONG_MIN) {}
  LLMax(ll v_) : v(v_) {}
  operator ll() { return v; }
  LLMax operator+(const LLMax& o) const { return LLMax(max(v, o.v)); };
};


int main() {
  LLMax x(7), y(-3);
  cout << x + y << endl;
  cout << LLMax() + y << endl;
  cout << LLMax(ll()) + y << endl;
  return 0;
}
