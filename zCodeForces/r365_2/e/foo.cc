#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

/*
template<typename A, typename B>
B mapget(const map<A, B>& mp, const A& a) {
  auto it = mp.find(a);
  if (it == mp.end()) return B();
  return it->second;
}

template<typename A, typename B>
void mapset(map<A, B>& mp, const A& a, B val) {
  if (val == B()) mp.erase(a);
  else            mp[a] = val;
}

*/

template<typename MP, typename A = typename MP::key_type, typename B = typename MP::mapped_type>
B mapget(const MP& mp, const A& a) {
  auto it = mp.find(a);
  if (it == mp.end()) return B();
  return it->second;
}

template<typename MP, typename A = typename MP::key_type, typename B = typename MP::mapped_type>
void mapset(MP& mp, const A& a, B val) {
  if (val == B()) mp.erase(a);
  else            mp[a] = val;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  map<ll, ll> mp{{3, 10}};
  mapset(mp, 5, 0);
  mapset(mp, 2, 6);
  REP(i, 6)  cout << i << " " << mapget(mp, i) << endl;
  cout << endl;
  for (auto [a, b] : mp) cout << a << " " << b << endl;



  return 0;
}

