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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  vector<ll> prv(N, -1LL);
  vector<ll> nxt(N, -1LL);
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x, y; cin >> x >> y; x--; y--;
      nxt[x] = y;
      prv[y] = x;
    }else if (tp == 2) {
      ll x, y; cin >> x >> y; x--; y--;
      nxt[x] = -1;
      prv[y] = -1;
    }else if (tp == 3) {
      ll x; cin >> x; x--;
      vector<ll> ans;
      ll t = x;
      while (prv[t] != -1) t = prv[t];
      while (t != -1) {
        ans.push_back(t);
        t = nxt[t];
      }
      cout << SIZE(ans);
      for (ll y : ans) cout << " " << y + 1;
      cout << "\n";

    }else assert(0);
  }

  return 0;
}

