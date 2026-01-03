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
  vector<ll> T(N);
  vector A(N, vector<ll>());
  REP(i, 0, N) {
    cin >> T[i];
    ll k; cin >> k;
    REP(j, 0, k) {
      ll a; cin >> a; a--;
      A[i].push_back(a);
    }
  }
  vector done(N, false);
  ll ans = 0;
  auto f = [&](auto rF, ll n) -> void {
    if (done[n]) return;
    done[n] = true;
    for (ll a : A[n]) rF(rF, a);
    ans += T[n];
  };
  f(f, N - 1);
  cout << ans << endl;

  return 0;
}

