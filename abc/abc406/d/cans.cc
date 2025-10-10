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
  // @InpMVec(N, ((X, dec=1), (Y, dec=1))) [UQ0RDQen]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; v2 -= 1; Y[i] = v2;
  }
  // @End [UQ0RDQen]

  vector<set<ll>> row(H);
  vector<set<ll>> col(W);
  REP(i, 0, N) {
    row[X[i]].insert(i);
    col[Y[i]].insert(i);
  }
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x; x--;
      cout << ssize(row[x]) << "\n";
      for (ll i : row[x]) col[Y[i]].erase(i);
      row[x] = set<ll>();
    }else if (tp == 2) {
      ll y; cin >> y; y--;
      cout << ssize(col[y]) << "\n";
      for (ll i : col[y]) row[X[i]].erase(i);
      col[y] = set<ll>();
    }
  }

  return 0;
}

