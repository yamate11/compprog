#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  vector<ll> nxt(N + 1, -1);
  vector<ll> prv(N + 1, -1);
  REP(_q, Q) {
    ll tp; cin >> tp;
    ll x = -1, y = -1;
    if (tp == 1) {
      cin >> x >> y;
      prv[y] = x;
      nxt[x] = y;
    }else if (tp == 2) {
      cin >> x >> y;
      nxt[x] = -1;
      prv[y] = -1;
    }else if (tp == 3) {
      cin >> x;
      vector<ll> vec;
      ll t = x;
      while (t > 0) {
        vec.push_back(t);
        t = prv[t];
      }
      reverse(ALL(vec));
      t = nxt[x];
      while (t > 0) {
        vec.push_back(t);
        t = nxt[t];
      }
      cout << SIZE(vec);
      for (ll p : vec) cout << " " << p;
      cout << "\n";
    }
  }

  return 0;
}

