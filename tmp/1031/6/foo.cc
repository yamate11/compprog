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

template<typename MP>
typename MP::mapped_type mapget(MP& mp,
            const typename MP::key_type& a,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  auto it = mp.find(a);
  return it == mp.end() ? def : it->second;
}


/*
template<typename MP>
void mapset(MP& mp,
            const typename MP::key_type& a,
            typename MP::mapped_type&& val,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  if (val == def) mp.erase(a);
  else mp[a] = forward<typename MP::mapped_type>(val);
}
*/

template<typename MP, typename T>
void mapset(MP& mp,
            const typename MP::key_type& a,
            T&& val,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  if (val == def) mp.erase(a);
  else mp[a] = forward<T>(val);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  map<ll, ll> mp;
  const ll x = 20;
  mapset(mp, 5, x);
  ll y = 20;
  mapset(mp, 4, move(y));

  return 0;
}
