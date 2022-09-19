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

// @@ !! LIM(mapget)

// ---- inserted library file mapget.cc

template<typename MP>
typename MP::mapped_type mapget(MP& mp,
            const typename MP::key_type& a,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  auto it = mp.find(a);
  return it == mp.end() ? def : it->second;
}


template<typename MP>
void mapset(MP& mp,
            const typename MP::key_type& a,
            typename MP::mapped_type&& val,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  if (val == def) mp.erase(a);
  else mp[a] = forward<typename MP::mapped_type>(val);
}

// ---- end mapget.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [Eh6mAhPP]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Eh6mAhPP]
  vector<ll> S(N + 1);
  map<ll, ll> mp;
  REP(i, 0, N) {
    S[i + 1] = S[i] + A[i];
    mp[S[i]]++;
  }
  mp[S[N]]++;
  ll ans = 0;
  REP(i, 0, N) {
    mp[S[i]]--;
    ans += mapget(mp, K + S[i]);
  }
  cout << ans << endl;

  return 0;
}

