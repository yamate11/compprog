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

  ll N; cin >> N;
  using ev_t = pair<ll, ll>;
  vector<ev_t> event;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    event.emplace_back(a, 1);
    event.emplace_back(a + b, -1);
  }
  sort(ALL(event));
  vector<ll> ans(N + 1);
  ll cur = 0;
  ll prev = 0;
  for (auto [day, diff] : event) {
    ans[cur] += day - prev;
    cur += diff;
    prev = day;
  }
  for (ll k = 1; k <= N; k++) {
    cout << ans[k] << " ";
  }
  cout << endl;

  return 0;
}

