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
  map<ll, set<ll>> fwd;
  REP(_q, 0, Q) {
    ll t, a, b; cin >> t >> a >> b; 
    if (t == 1) {
      fwd[a].insert(b);
      // bwd[b].insert(a);
    }else if (t == 2) {
      fwd[a].erase(b);
      // bwd[b].erase(a);
    }else if (t == 3) {
      if (fwd[a].contains(b) and fwd[b].contains(a)) {
        cout << "Yes\n";
      }else {
        cout << "No\n";
      }
    }else assert(0);
  }

  return 0;
}

