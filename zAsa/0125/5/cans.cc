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

  ll N; cin >> N;
  // @InpMVec(N, (R, H)) [1fEqcLLS]
  auto R = vector(N, ll());
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; R[i] = v1;
    ll v2; cin >> v2; H[i] = v2;
  }
  // @End [1fEqcLLS]

  ll lim = 1e5;
  vector vec(lim + 1, vector(4, 0LL));
  REP(i, 0, N) {
    vec[R[i]][0]++;
    vec[R[i]][H[i]]++;
  }
  vector S(lim + 2, 0LL);
  REP(i, 0, lim + 1) S[i + 1] = S[i] + vec[i][0];
  REP(i, 0, N) {
    ll r = R[i];
    ll h = H[i];
    ll win = 0, lose = 0, draw = 0;
    win += S[r];
    draw = vec[r][h] - 1;
    ll hh = ((h - 1) + 1) % 3 + 1;
    win += vec[r][hh];
    lose = N - (win + draw + 1);
    cout << win << " " << lose << " " << draw << "\n";
  }
  

  return 0;
}

