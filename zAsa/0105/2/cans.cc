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

  auto g = [&](ll x, ll y, ll z) -> ll { return x * x + y * y + z * z + x * y + y * z + z * x; };

  ll N; cin >> N;
  vector<ll> cnt(N + 1);
  REP(x, 1, N + 1) {
    REP(y, 1, N + 1) {
      REP(z, 1, N + 1) {
        ll a = g(x, y, z);
        if (a > N) break;
        cnt[a]++;
      }
    }
  }
  REPOUT(i, 1, N + 1, cnt[i], "\n");

  return 0;
}

