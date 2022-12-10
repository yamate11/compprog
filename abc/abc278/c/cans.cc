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

// @@ !! LIM(mapget)

// ---- inserted library file mapget.cc

template<typename MP>
typename MP::mapped_type mapget(MP& mp,
            const typename MP::key_type& a,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  auto it = mp.find(a);
  return it == mp.end() ? def : it->second;
}


template<typename MP, typename T>
void mapset(MP& mp,
            const typename MP::key_type& a,
            T&& val,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  if (val == def) mp.erase(a);
  else mp[a] = forward<T>(val);
}

// ---- end mapget.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  map<ll, set<ll>> mp;
  auto fol = [&](ll x, ll y) -> bool {
    auto it = mp.find(x);
    if (it == mp.end()) return false;
    return it->second.find(y) != it->second.end();
  };
  REP(i, 0, Q) {
    ll t, a, b; cin >> t >> a >> b;
    if (t == 1) {
      mp[a].insert(b);
    }else if (t == 2) {
      auto it = mp.find(a);
      if (it != mp.end()) it->second.erase(b);
    }else if (t == 3) {
      cout << (fol(a, b) and fol(b, a) ? "Yes\n" : "No\n");
    }
  }

  return 0;
}

