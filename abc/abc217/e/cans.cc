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

  ll Q; cin >> Q;
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  deque<ll> deq;
  for (; Q > 0; Q--) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x;
      deq.push_back(x);
    }else if (tp == 2) {
      ll y;
      if (! pque.empty()) {
        y = pque.top(); pque.pop();
      }else {
        assert(! deq.empty());
        y = deq.front(); deq.pop_front();
      }
      cout << y << "\n";
    }else if (tp == 3) {
      while (! deq.empty()) {
        ll y = deq.front(); deq.pop_front();
        pque.push(y);
      }
    }
  }
  

  return 0;
}

