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
  // @InpMVec(N, ((P, type=char), (V, type=string))) [5A64AxBG]
  auto P = vector(N, char());
  auto V = vector(N, string());
  for (int i = 0; i < N; i++) {
    char v1; cin >> v1; P[i] = v1;
    string v2; cin >> v2; V[i] = v2;
  }
  // @End [5A64AxBG]
  
  vector<ll> ans(6, -1LL);
  REP(i, 0, N) {
    ll d = P[i] - 'A';
    if (ans[d] < 0 and V[i] == "AC") {
      ans[d] = i;
    }
  }
  REPOUT(i, 0, 6, ans[i] + 1, "\n");

  return 0;
}

