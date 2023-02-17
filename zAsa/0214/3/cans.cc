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

template<typename MP>
struct mgs : MP {
  using Key = typename MP::key_type;
  using T = typename MP::mapped_type;

  T def;

  mgs(const T& def_ = T()) : MP(), def(def_) {}
  mgs(const mgs& o) : MP(), def(o.def) {}
  mgs(mgs&& o) : MP(), def(move(o.def)) {}
  mgs& operator =(const mgs& o) {
    MP::operator=(o);
    def = o.def;
    return *this;
  }

  const T& get(const Key& k) const {
    auto it = this->find(k);
    if (it == this->end()) return def;
    else return it->second;
  }

  template<typename T1>
  void set(const Key& k, T1&& t) {
    if (t == def) this->erase(k);
    else (*this)[k] = forward<T1>(t);
  }
};


int main() {
  ll N; cin >> N;
  mgs<map<ll, ll>> mp(0);
  REP(i, 0, N) {
    ll a; cin >> a;
    mp.set(i, a);
  }
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x;
      mp = mgs<map<ll, ll>>(x);
    }else if (tp == 2) {
      ll i, x; cin >> i >> x; i--;
      mp.set(i, mp.get(i) + x);
    }else if (tp == 3) {
      ll i; cin >> i; i--;
      cout << mp.get(i) << endl;
    }
  }

  return 0;
}

