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

  vector<ll> X, Y;
  X.push_back(1);
  Y.push_back(0);
  vector<ll> query;
  ll cx = 1, cy = 0;
  ll t = 0;
  REP(q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      char c; cin >> c;
      if (c == 'U') cy++;
      else if (c == 'D') cy--;
      else if (c == 'R') cx++;
      else if (c == 'L') cx--;
      else assert(0);
      X.push_back(cx);
      Y.push_back(cy);
      t++;
    }else if (tp == 2) {
      ll n; cin >> n;
      if (t <= n - 1) {
        cout << n - t << " " << 0 << "\n";
      }else {
        cout << X[t - n + 1] << " " << Y[t - n + 1] << "\n";
      }
    }else assert(0);
  }

  return 0;
}

