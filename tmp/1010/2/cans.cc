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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((P, dec=1), (S, type=string))) [Ib5QdY6U]
  auto P = vector(M, ll());
  auto S = vector(M, string());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; P[i] = v1;
    string v2; cin >> v2; S[i] = v2;
  }
  // @End [Ib5QdY6U]
  vector<bool> AC(N);
  ll ac = 0;
  ll wa = 0;
  REPrev(i, M - 1, 0) {
    ll q = P[i];
    if (S[i] == "AC") {
      if (not AC[q]) {
        ac++;
        AC[q] = true;
      }
    }else if (S[i] == "WA") {
      if (AC[q]) {
        wa++;
      }
    }
  }
  cout << ac << " " << wa << "\n";
  return 0;
}

