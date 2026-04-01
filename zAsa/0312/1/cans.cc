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

  ll N, L; cin >> N >> L;
  ll left = L;
  ll right = L + N - 1;
  ll r;
  if (left <= 0 and 0 <= right) r = 0;
  else if (left > 0) r = left;
  else if (right < 0) r = right;
  else assert(0);
  ll ans = 0;
  REP(i, 1, N + 1) {
    ll x = L + i - 1;
    if (x != r) ans += x;
  }
  cout << ans << endl;

  return 0;
}

