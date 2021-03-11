#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  string s; cin >> s;
  ll sz = s.size();
  vector<bool> cs(128);
  for (ll i = 0; i < n; i++) cs[s[i]] = true;
  set<char> set0;
  for (ll c = 'a'; c <= 'z'; c++) if (cs[c]) set0.insert(c);
  char small = *set0.begin();
  auto it2 = set0.end(); it2--;
  char large = *it2;
  string ans(k, small);
  if (k <= sz) {
    for (ll i = 0; i < k; i++) ans[i] = s[i];
    ll i = k - 1;
    for ( ; i >= 0 && s[i] == large; i--);
    auto it = set0.find(s[i]);
    it++;
    ans[i] = *it;
    for (ll j = i + 1; j < k; j++) ans[j] = small;
  }else {
    for (ll i = 0; i < sz; i++) ans[i] = s[i];
    for (ll i = sz; i < k; i++) ans[i] = small;
  }
  cout << ans << endl;

  return 0;
}

