#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  ll k; cin >> k;
  ll sz = s.size();
  vector<bool> vec(127);
  for (char c : s) vec[c] = true;
  ll cnt = 0;
  for (ll c = 'a'; c <= 'z'; c++) if (vec[c]) cnt++;
  if (sz < k) {
    cout << "impossible\n";
  }else {
    cout << max(0LL, k - cnt) << endl;
  }


  return 0;
}

