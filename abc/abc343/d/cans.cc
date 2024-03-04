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

// @@ !! LIM(mapget)

// ---- inserted library file mapget.cc

template<typename MP>
struct mgs : MP {
  using Key = typename MP::key_type;
  using T = typename MP::mapped_type;

  T def;

  mgs(const T& def_ = T()) : MP(), def(def_) {}
  mgs(const mgs& o) : MP(o), def(o.def) {}
  mgs(mgs&& o) : MP(move(o)), def(move(o.def)) {}
  mgs& operator =(const mgs& o) {
    MP::operator=(o);
    def = o.def;
    return *this;
  }
  mgs& operator =(mgs&& o) {
    MP::operator=(move(o));
    def = move(o.def);
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

// ---- end mapget.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, T; cin >> N >> T;
  vector vec(N, 0LL);
  mgs<map<ll, ll>> mp;
  mp.set(0, N);
  ll cnt = 1;
  REP(t, 0, T) {
    ll a, b; cin >> a >> b; a--;
    ll x = vec[a];
    ll y = x + b;
    mp[x]--;
    if (mp[x] == 0) cnt--;
    if (mp[y] == 0) cnt++;
    mp[y]++;
    vec[a] = y;
    cout << cnt << "\n";
  }
  
  


  return 0;
}

