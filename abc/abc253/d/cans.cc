#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, A, B; cin >> N >> A >> B;
  ll g = gcd(A, B);
  ll l = A / g * B;
  ll na = N / A, nb = N / B, nl = N / l;
  ll ma = A * na * (na + 1) / 2;
  ll mb = B * nb * (nb + 1) / 2;
  ll ml = l * nl * (nl + 1) / 2;
  ll tot = N * (N + 1) / 2;
  cout << tot - (ma + mb - ml) << endl;

  return 0;
}

