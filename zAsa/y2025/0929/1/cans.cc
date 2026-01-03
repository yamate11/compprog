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

  // @InpVec(3, A) [AEn5YHiZ]
  auto A = vector(3, ll());
  for (int i = 0; i < 3; i++) { ll v; cin >> v; A[i] = v; }
  // @End [AEn5YHiZ]

  ll t = A[0] + A[1] + A[2];
  if (t >= 22) {
    cout << "bust\n";
  }else {
    cout << "win\n";
  }

  return 0;
}

