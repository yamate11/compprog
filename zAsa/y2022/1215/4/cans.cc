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
  // @InpVec(N, R) [LzHY6UGf]
  auto R = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; R[i] = v; }
  // @End [LzHY6UGf]


  ll d = 0;
  REP(i, 0, N - 1) {
    if (R[i + 1] > R[i]) { d = 1; break; }
    if (R[i + 1] < R[i]) { d = -1; break; }
  }
  if (d == 0) {
    cout << 0 << endl;
    return 0;
  }
  
  ll i = 0;
  ll cnt = 0;
  while (true) {
    while (i + 1 < N and (R[i + 1] - R[i]) * d >= 0) i++;
    if (i + 1 == N) break;
    i++;
    cnt++;
    d = -d;
  }
  if (cnt > 0) cnt += 2;
  cout << cnt << endl;


  return 0;
}

