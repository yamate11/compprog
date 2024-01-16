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

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((P, dec=1), (S, type=string))) [rYBdjydG]
  auto P = vector(M, ll());
  auto S = vector(M, string());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; P[i] = v1;
    string v2; cin >> v2; S[i] = v2;
  }
  // @End [rYBdjydG]

  vector vac(N, false);
  vector fac(N, false);
  ll ac = 0;
  ll pen = 0;
  REP(i, 0, M) {
    if (S[i] == "AC") {
      fac[P[i]] = true;
    }
  }
  REP(i, 0, N) if (fac[i]) ac++;
  REP(i, 0, M) {
    if (S[i] == "AC") vac[P[i]] = true;
    else {
      if (fac[P[i]] and not vac[P[i]]) pen++;
    }
  }
  cout << ac << " " << pen << endl;

  return 0;
}

