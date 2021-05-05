#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  auto store = vector(2, vector<char>());
  ll idx = 0;
  for (ll i = 0; i < (ll)S.size(); i++) {
    if (S[i] == 'R') { idx = 1 - idx; }
    else {
      if (store[idx].size() == 0 || store[idx].back() != S[i]) {
        store[idx].push_back(S[i]);
      }else {
        store[idx].pop_back();
      }
    }
  }
  ll i = 0;
  for (; i < (ll)store[0].size() && i < (ll)store[1].size()
         && store[0][i] == store[1][i]
         ; i++);
  string ans;
  for (ll j = (ll)store[1 - idx].size() - 1; j >= i; j--) {
    ans += store[1 - idx][j];
  }
  for (ll j = i; j < (ll)store[idx].size(); j++) {
    ans += store[idx][j];
  }
  cout << ans << endl;

  return 0;
}

