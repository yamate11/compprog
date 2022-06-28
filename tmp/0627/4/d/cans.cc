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

using pll = pair<ll, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // vector<ll> A(N), B(N); REP(i, N) { cin >> A[i] >> B[i]; A[i]--; }
  using ev_t = pll;
  vector<ev_t> event;
  ll IN = 2, OUT = 1;
  REP(i, N) {
    ll a, b; cin >> a >> b;
    event.emplace_back(a, IN);
    event.emplace_back(a + b, OUT);
  }
  sort(ALL(event));
  vector<ll> ans(N + 1);
  ll day = 0;
  ll in = 0;
  for (auto [d, tp] : event) {
    ans[in] += d - day;
    day = d;
    if (tp == OUT) in--;
    else in++;
  }
  REP2(i, 1, N + 1) cout << ans[i] << " ";
  cout << endl;

  return 0;
}

