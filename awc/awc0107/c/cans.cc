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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpMVec(N, ((S, type=string), V)) [p2cJDH9q]
  auto S = vector(N, string());
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) {
    string v1; cin >> v1; S[i] = v1;
    ll v2; cin >> v2; V[i] = v2;
  }
  // @End [p2cJDH9q]

  using sta = pair<ll, string>;
  map<ll, vector<sta>> mp;
  REP(i, 0, N) {
    mp[V[i]].emplace_back(i, move(S[i]));
  }
  ll big = 1e18;
  mp[big].emplace_back(-1, "");
  mp[-big].emplace_back(-1, "");

  REP(_q, 0, Q) {
    ll x; cin >> x;
    auto it = mp.find(x);
    if (it != mp.end()) {
      for (const auto& [i, s] : it->second) {
        cout << s << " ";
      }
      cout << "\n";
    }else {
      it = mp.lower_bound(x);
      ll hiv = it->first;
      const auto& [hi_id, hi_s] = it->second[0];
      it--;
      ll lov = it->first;
      const auto& [lo_id, lo_s] = it->second[0];
      if (hiv - x < x - lov) {
        cout << hi_s << "\n";
      }else if (hiv - x > x - lov) {
        cout << lo_s << "\n";
      }else if (hi_id < lo_id) {
        cout << hi_s << "\n";
      }else {
        cout << lo_s << "\n";
      }
    }
  }

  return 0;
}

