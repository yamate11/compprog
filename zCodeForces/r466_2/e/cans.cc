#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, c; cin >> n >> c;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  ll tot = 0;
  for (ll i = 0; i < n; i++) tot += A[i];
  using sta = pair<ll, ll>;
  deque<sta> deq;
  vector<ll> tbl(n + 1);
  for (ll i = 0; i < n; i++) {
    sta tp = sta(A[i], -i);
    while (!deq.empty() && deq.back() > tp) deq.pop_back();
    deq.push_back(tp);
    auto [v, mi] = deq.front();
    if (-mi <= i - c) {
      deq.pop_front();
      assert(!deq.empty());
      tie(v, mi) = deq.front();
    }
    if (i + 1 - c >= 0) {
      tbl[i + 1] = max(tbl[i], tbl[i + 1 - c] + v);
    }else {
      tbl[i + 1] = 0;
    }
  }
  cout << tot - tbl[n] << endl;
  return 0;
}

