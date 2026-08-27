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

  ll H, W, N; cin >> H >> W >> N;
  vector R(H, set<ll>());
  vector C(W, set<ll>());
  REP(i, 0, N) {
    ll x, y; cin >> x >> y; x--; y--;
    R[x].insert(y);
    C[y].insert(x);
  }
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x; x--;
      cout << ssize(R[x]) << "\n";
      for (ll y : R[x]) C[y].erase(x);
      R[x] = set<ll>();
    }else if (tp == 2) {
      ll y; cin >> y; y--;
      cout << ssize(C[y]) << "\n";
      for (ll x : C[y]) R[x].erase(y);
      C[y] = set<ll>();
    }
  }


  return 0;
}

