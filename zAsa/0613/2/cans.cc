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

  ll N; cin >> N;
  // @InpMVec(N, ((S, type=string), P)) [RbbWbIh1]
  auto S = vector(N, string());
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) {
    string v1; cin >> v1; S[i] = v1;
    ll v2; cin >> v2; P[i] = v2;
  }
  // @End [RbbWbIh1]

  ll t = 0;
  REP(i, 0, N) t += P[i];
  REP(i, 0, N) {
    if (P[i] * 2 > t) {
      cout << S[i] << endl;
      return 0;
    }
  }
  cout << "atcoder\n";

  return 0;
}

