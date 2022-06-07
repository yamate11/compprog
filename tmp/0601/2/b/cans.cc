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

  ll a, b; cin >> a >> b;
  vector rec(10, 0LL);
  REP(i, a) {
    ll j;
    cin >> j;
    if (j == 0) j = 9;
    else j--;
    rec[j] = 1;
  }
  REP(i, b) {
    ll j;
    cin >> j;
    if (j == 0) j = 9;
    else j--;
    rec[j] = 2;
  }
  vector<ll> xs = {3, 2, 2, 1, 1, 1, 0, 0, 0, 0};
  vector<ll> ys = {3, 2, 4, 1, 3, 5, 0, 2, 4, 6};
  vector<string> s(4, "       ");
  REP(i, 10) {
    ll v = rec[i];
    s[xs[i]][ys[i]] = v == 0 ? 'x' : v == 1 ? '.' : 'o';
  }
  REP(j, 4) cout << s[j] << "\n";

  return 0;
}

