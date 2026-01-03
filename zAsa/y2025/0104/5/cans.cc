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
  ll lim = 1e6;
  vector<ll> A(lim + 2);
  REP(i, 0, N) {
    ll a, b; cin >> a >> b;
    A[a]++;
    A[b + 1]--;
  }
  ll c = 0;
  ll ans = 0;
  REP(i, 0, lim + 1) {
    c += A[i];
    ans = max(ans, c);
  }
  cout << ans << endl;

  return 0;
}

