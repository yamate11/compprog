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
  // @InpVec(N, A) [TXa6HFHp]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [TXa6HFHp]

  ll q = *max_element(ALL(A));
  ll a = 0, b = 0;
  REP(i, 0, N) {
    if (A[i] == q) a++;
    else if (A[i] == q - 1) b++;
    else {
      cout << "No\n";
      return 0;
    }
  }
  if (b + 1 <= q and q <= b + (a / 2)) {
    cout << "Yes\n";
  }else if (b == 0 and q == N - 1) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

