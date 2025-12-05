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

  auto f = [&](ll x) -> ll {
    ll ret = 0;
    while (x > 0) {
      ret += x % 10;
      x /= 10;
    }
    return ret;
  };

  vector<ll> A(N + 1);
  vector<ll> B(N + 1);
  A[0] = 1;
  B[0] = f(1);
  REP(i, 1, N + 1) {
    ll s = 0;
    REP(j, 0, i) s += B[j];
    A[i] = s;
    B[i] = f(A[i]);
  }
  cout << A[N] << endl;

  return 0;
}

