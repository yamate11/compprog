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

  auto func = [&](string X, string Y) -> bool {
    ll sz = SIZE(X);
    assert(sz == SIZE(Y));
    ll ya = 0;
    ll yb = 0;
    ll xa = 0;
    ll xb = 0;
    ll xc = 0;
    REP(i, 0, sz) {
      if (Y[i] == 'A') ya++;
      else if (Y[i] == 'B') yb++;
      else assert(0);
      if (X[i] == 'A') xa++;
      else if (X[i] == 'B') xb++;
      else if (X[i] == 'C') xc++;
      else assert(0);
    }
    if (ya > xa + xc or yb > xb + xc) return false;
    ll t = 0;
    REP(i, 0, sz) {
      if (X[i] == 'C') {
        if (t < ya - xa) {
          X[i] = 'A';
          t++;
        }else {
          X[i] = 'B';
        }
      }
    }
    ll xxa = 0;
    ll yya = 0;
    REP(i, 0, sz) {
      if (X[i] == 'A') xxa++;
      if (Y[i] == 'A') yya++;
      if (yya > xxa) return false;
    }
    return true;
  };

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    string X, Y; cin >> X >> Y;
    ll prev = -1;
    REP(i, 0, N + 1) {
      if (i == N or Y[i] == 'C') {
        if (i < N and X[i] != 'C') return false;
        if (not func(X.substr(prev + 1, i - prev - 1), Y.substr(prev + 1, i - prev - 1))) return false;
        prev = i;
      }
    }
    return true;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

