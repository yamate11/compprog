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

  ll N, M, K; cin >> N >> M >> K;
  vector A(M, 0LL);
  vector<char> R(M);
  REP(i, 0, M) {
    ll c; cin >> c;
    ll y = 0;
    REP(j, 0, c) {
      ll a; cin >> a; a--;
      y |= (1LL << a);
    }
    A[i] = y;
    cin >> R[i];
  }
  ll ans = 0;
  REP(x, 0, 1LL << N) {
    auto check = [&]() -> bool {
      REP(i, 0, M) {
        u64 z = A[i] & x;
        if ((popcount(z) >= K) != (R[i] == 'o')) return false;
      }
      return true;
    };
    if (check()) ans++;
  }
  cout << ans << endl;
  return 0;
}

