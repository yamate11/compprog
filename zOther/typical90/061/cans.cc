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
  vector<ll> head;
  vector<ll> tail;
  for (ll q = 0; q < Q; q++) {
    ll t, x; cin >> t >> x;
    if (t == 1) {
      head.push_back(x);
    }else if (t == 2) {
      tail.push_back(x);
    }else if (t == 3) {
      ll hsz = head.size();
      if (x <= hsz) {
        cout << head[hsz - x] << "\n";
      }else {
        cout << tail[x - hsz - 1] << "\n";
      }
    }
  }

  return 0;
}

