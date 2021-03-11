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
  using s_t = tuple<ll, ll, ll>; // idx, val, len
  set<s_t> set1;
  set1.emplace(-100, -100, 0);
  set1.emplace(ll(1e9), -1000, 0);
  using p_t = pair<ll, ll>; // -len, idx
  set<p_t> set2;
  for (ll i = 0; i < n; ) {
    ll j = i + 1;
    for ( ; j < n && A[j] == A[i]; j++);
    set1.emplace(i, A[i], j - i);
    set2.emplace(- (j - i), i);
    i = j;
  }
  ll cnt = 0;
  while (!set2.empty()) {
    cnt++;
    auto [mlen, idx] = *set2.begin();
    set2.erase(set2.begin());
    auto it = set1.lower_bound(s_t(idx, -100, -100));
    auto it1 = it; it1--;
    auto it2 = it; it2++;
    auto [idx1, val1, len1] = *it1;
    auto [idx2, val2, len2] = *it2;
    set1.erase(it);
    if (val1 == val2) {
      set1.erase(it1);
      set1.erase(it2);
      set1.emplace(idx1, val1, len1 + len2);
      set2.erase(p_t(-len1, idx1));
      set2.erase(p_t(-len2, idx2));
      set2.emplace(-(len1 + len2), idx1);
    }
  }
  cout << cnt << endl;

  return 0;
}

