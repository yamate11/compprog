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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  // @InpVec(5, A) [XF5qPTHM]
  vector<ll> A(5);
  for (int i = 0; i < 5; i++) { ll v; cin >> v; A[i] = v; }
  // @End [XF5qPTHM]
  ll K; cin >> K;
  REP(i, 0, 5) REP(j, i + 1, 5) {
    if (abs(A[i] - A[j]) > K) {
      cout << ":(\n";
      return 0;
    }
  }
  cout << "Yay!\n";
  

  return 0;
}

