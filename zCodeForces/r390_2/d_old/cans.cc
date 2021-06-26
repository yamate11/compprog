#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  using ev_t = tuple<ll, ll, ll>; // time, on/off, idx
  vector<ev_t> ev;
  vector<ll> L(n), R(n);
  for (ll i = 0; i < n; i++) {
    ll l, r; cin >> l >> r; l--;
    L[i] = l;
    R[i] = r;
    ev.emplace_back(l, 1, i);
    ev.emplace_back(r, 0, i);
  }
  sort(ev.begin(), ev.end());
  using sta = pair<ll, ll>; // end_time, idx
  tree<sta, null_type, less<sta>, rb_tree_tag, tree_order_statistics_node_update> tr;
  ll dmax = 0;
  ll arg0, arg1;
  for (auto [t, op, idx] : ev) {
    if (op == 1) {
      tr.insert(sta(R[idx], idx));
      ll sz = tr.size();
      if (sz >= k) {
	auto it = tr.find_by_order(sz - k);
	auto [rr, j] = *it;
	ll duration = rr - t;
	if (dmax < duration) {
	  dmax = duration;
	  arg0 = t;
	  arg1 = rr;
	}
      }
    }else if (op == 0) {
      tr.erase(sta(t, idx));
    }else assert(0);
  }
  if (dmax == 0) {
    cout << 0 << endl;
    for (ll i = 0; i < k; i++) {
      if (i > 0) cout << " ";
      cout << i + 1;
    }
    cout << endl;
  }else {
    cout << dmax << endl;
    ll cnt = 0;
    bool first = true;
    for (ll i = 0; i < n; i++) {
      if (L[i] <= arg0 && arg1 <= R[i]) {
	if (first) first = false;
	else cout << " ";
	cout << i + 1;
	cnt++;
	if (cnt == k) break;
      }
    }
    cout << endl;
  }


  return 0;
}

