#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(strSearch)
// --> strSearch
// ---- inserted library file strSearch.cc
vector<int> zAlg(string s) {
  int n = s.size();
  vector<int> z(n);
  z.at(0) = n;
  int i = 1;
  int j = 0;
  while (i < n) {
    for ( ; i+j < n && s.at(j) == s.at(i+j); j++) {}
    z.at(i++) = j;
    if (j > 0) {
      for (int k = 1; i < n && z.at(k) < j-1; k++, j--, i++) z.at(i) = z.at(k);
      j--;
    }
  }
  return z;
}

// matches("abab", "xababab") --> [1,3]
vector<int> matches(string p, string s, char sepChar = '\xff') {
  auto v = zAlg(p + string(1, sepChar) + s);
  int n = p.size();
  vector<int> res;
  for (size_t i = 0; i < s.size() - (n-1); i++) {
    if (v.at(n+1 + i) == n) res.push_back(i);
  }
  return res;
}
// ---- end strSearch.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  auto z1 = zAlg(S);
  string R(S); reverse(R.begin(), R.end());
  auto z2 = zAlg(R);
  ll N = S.size();
  ll cnt = 0;
  for (ll i = (N+2) / 2; i < N-1; i++) {
    ll x = min(N-i-1, (ll)z1.at(i)) + min(N-i-1, (ll)z2.at(N-i));
    if (x >= N-i) cnt += x - (N-i) + 1;
  }
  cout << cnt << endl;

  return 0;
}

