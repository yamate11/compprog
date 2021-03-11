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
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  ll big = 1e9;
  ll bot = big;
  ll ans = 0;
  for (ll i = 0; i < 2 * n; i++) {
    string s; cin >> s;
    if (s == "add") {
      ll t; cin >> t;
      if (!pque.empty() && pque.top() < t) bot = pque.top();
      pque.push(t);
    }else if (s == "remove") {
      assert(!pque.empty());
      if (pque.top() == bot) {
        ans++;
        bot = big;
      }
      pque.pop();
    }else assert(0);
  }
  cout << ans << endl;
  return 0;
}

