#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  ll lim = 2e5;
  vector<ll> cnt(lim + 1);
  ll vmax = 0;
  ll maxa = -1;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    A[i] = a;
    cnt[a]++;
    if (cnt[a] > vmax) {
      vmax = cnt[a];
      maxa = a;
    }
  }
  ll stage = 0;
  using sta = tuple<ll, ll, ll>;
  vector<sta> ops;
  for (ll i = 0; i < n; i++) {
    if (stage == 0) {
      if (A[i] == maxa) {
	reverse(ops.begin(), ops.end());
	stage = 1;
      }else if (A[i] < maxa) {
	ops.emplace_back(1, i, i+1);
      }else {
	ops.emplace_back(2, i, i+1);
      }
    }else {
      if (A[i] < maxa) {
	ops.emplace_back(1, i, i-1);
      }else if (A[i] > maxa) {
	ops.emplace_back(2, i, i-1);
      }
    }
  }
  ll m = ops.size();
  cout << m << endl;
  for (ll i = 0; i < m; i++) {
    auto [x, y, z] = ops[i];
    cout << x << " " << y + 1 << " " << z + 1 << "\n";
  }

  return 0;
}

