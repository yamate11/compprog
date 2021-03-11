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
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  ll k; cin >> k;
  vector<ll> B(k);
  for (ll i = 0; i < k; i++) cin >> B[i];
  using sta = pair<ll, ll>;
  vector<sta> spec;
  {
    ll p = 0;
    for (ll i = 0; i < k; i++) {
      ll s = 0;
      ll p0 = p;
      while (s < B[i] && p < n) {
	s += A[p];
	p++;
      }
      if (s != B[i]) {
	cout << "NO" << endl;
	return 0;
      }
      spec.emplace_back(p0, p - p0);
    }
    if (p < n) {
      cout << "NO" << endl;
      return 0;
    }
  }
  using stb = pair<ll, char>;
  vector<stb> ans;
  auto func = [&](ll p, ll len) -> bool {
    if (len == 1) return true;
    bool same = true;
    for (ll i = 0; i < len - 1; i++) if (A[p + i] != A[p + i+1]) same = false;
    if (same) return false;
    ll vmax = 0;
    for (ll i = 0; i < len; i++) {
      if (A[p + i] > vmax) {
	vmax = A[p + i];
      }
    }
    for (ll i = 0; i < len; i++) {
      if (A[p + i] != vmax) continue;
      if (i > 0 && A[p + i - 1] < A[p + i]) {
	for (ll j = i; j > 0; j--) ans.emplace_back(p + j, 'L');
	for (ll j = i + 1; j < len; j++) ans.emplace_back(p, 'R');
	return true;
      }else if (i + 1 < len && A[p + i] > A[p + i + 1]) {
	for (ll j = i + 1; j < len; j++) ans.emplace_back(p + i, 'R');
	for (ll j = i; j > 0; j--) ans.emplace_back(p + j, 'L');
	return true;
      }
    }
    assert(0);
  };
  while (!spec.empty()) {
    auto [p, len] = spec.back(); spec.pop_back();
    if (!func(p, len)) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for (auto [i, c] : ans) {
    cout << i + 1 << " " << c << "\n";
  }

  return 0;
}

