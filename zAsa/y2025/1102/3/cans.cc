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

  priority_queue<ll, vector<ll>, greater<ll>> pque;

  ll Q; cin >> Q;
  ll cur = 0;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      pque.push(cur);
    }else if (tp == 2) {
      ll t; cin >> t;
      cur += t;
    }else if (tp == 3) {
      ll h; cin >> h;
      ll cnt = 0;
      while (not pque.empty()) {
        ll x = pque.top();
        if (x > cur - h) break;
        cnt++;
        pque.pop();
      }
      cout << cnt << "\n";
    }else assert(0);
      
  }

  return 0;
}

