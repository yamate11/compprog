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
  // @InpVec(2*N, P) [fPtnTBD4]
  auto P = vector(2*N, ll());
  for (int i = 0; i < 2*N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [fPtnTBD4]

  vector<ll> ans;
  REP(i, 0, N - 1) {
    ll a = 2 * i;
    ll b = a + 1;
    ll c = a + 2;
    if (P[a] > P[b] and P[a] > P[c]) {
      ans.push_back(a);
      swap(P[a], P[b]);
    }else if (P[a] < P[c] and P[b] < P[c]) {
      ans.push_back(b);
      swap(P[b], P[c]);
    }
  }
  ll a = 2 * (N - 1);
  ll b = a + 1;
  if (P[a] > P[b]) {
    ans.push_back(a);
    swap(P[a], P[b]);
  }
  cout << SIZE(ans) << endl;
  REPOUT(i, 0, SIZE(ans), ans[i] + 1, " ");

  return 0;
}

