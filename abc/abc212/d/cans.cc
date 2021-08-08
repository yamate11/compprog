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

  ll shift = 0;
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  ll Q; cin >> Q;
  for (; Q > 0; Q--) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x;
      pque.push(x - shift);
    }else if (tp == 2) {
      ll x; cin >> x;
      shift += x;
    }else if (tp == 3) {
      ll y = pque.top(); pque.pop();
      cout << y + shift << "\n";
    }
  }

  return 0;
}

