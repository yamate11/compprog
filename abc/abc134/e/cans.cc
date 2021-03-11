#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  multiset<ll> cur;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (cur.empty()) {
      cur.insert(a);
      continue;
    }
    auto it = cur.lower_bound(a);
    if (it == cur.begin()) {
      cur.insert(a);
      continue;
    }
    it--;
    cur.erase(it);
    cur.insert(a);
  }
  cout << cur.size() << endl;
  return 0;
}

