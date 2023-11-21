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
  // @InpVec(N, A) [Xg8fRILo]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Xg8fRILo]

  sort(ALL(A), greater<ll>());
  vector<ll> B;
  ll x = 0;
  for (ll i = 0; i < N; ) {
    if (i + 1 < N and A[i] == A[i + 1]) i += 2;
    else {
      x ^= A[i];
      B.push_back(A[i]);
      i++;
    }
  }
  if (x != 0) {
    cout << -1 << endl;
  }else if (B.empty()) {
    cout << 0 << endl;
  }else {
    cout << B[0] - 1 << endl;
  }
  

  return 0;
}

