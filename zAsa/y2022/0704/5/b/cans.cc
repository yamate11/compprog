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

  auto pout = [&](ll a, ll b) { cout << a + 1 << " " << b + 1 << "\n"; };

  ll N; cin >> N;
  if (N == 3) {
    cout << "2\n1 3\n2 3\n";
  }else if (N == 4) {
    cout << "4\n1 2\n1 3\n2 4\n3 4\n";
  }else if (N % 2 == 0) {
    ll m = 4 * N / 2;
    cout << m << "\n";
    REP(i, N / 2) {
      ll x = i;
      ll y = N - 1 - i;
      ll j = (i + 1) % (N / 2);
      ll p = j;
      ll q = N - 1 - j;
      pout(x, p); pout(x, q); pout(y, p); pout(y, q);
    }
  }else {
    ll m = (4 * (N - 4) + 3 * 4) / 2;
    cout << m << "\n";
    pout(N - 1, 0); pout(N - 1, N - 2); pout(N - 1, (N - 1) / 2 - 1); pout(N - 1, (N - 1) / 2);
    REP(i, (N - 1) / 2 - 1) {
      pout(i, i + 1); pout(i, N - i - 3); pout(N - 2 - i, i + 1); pout(N - 2 - i, N - i - 3);
    }
  }

  return 0;
}

