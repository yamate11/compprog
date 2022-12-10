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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, S) [3w1pkB9t]
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; S[i] = v; }
  // @End [3w1pkB9t]

  ll x = 0, y = 0;
  ll vx = 0, vy = 0;
  ll z = S[0];
  ll vz = S[0];
  REP(i, 0, N) {
    if (i % 3 == 1) {
      vx += S[i - 1] - S[i];
      x = max(x, vx);
    }else if (i % 3 == 2) {
      vy += S[i - 1] - S[i];
      y = max(y, vy);
    }else if (i >= 3 and i % 3 == 0) {
      vz += S[i] - S[i - 1];
      z = min(z, vz);
    }
  }
  if (x + y > z) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n" << x << " " << y;
  REP(i, 0, N) {
    ll t = S[i] - (x + y);
    cout << " " << t;
    x = y;
    y = t;
  }
  cout << endl;

  return 0;
}

