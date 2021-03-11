#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  vector<ll> w(n);
  for (ll i = 0; i < n; i++) cin >> w.at(i);
  vector<ll> x(m), y(m);
  vector<set<ll>> like(n);
  for (ll i = 0; i < m; i++) {
    ll xx, yy; cin >> xx >> yy; xx--; yy--;
    x.at(i) = xx;
    y.at(i) = yy;
    like.at(xx).insert(i);
    like.at(yy).insert(i);
  }
  queue<ll> que;
  vector<bool> checked_dish(n);
  for (ll i = 0; i < n; i++) {
    if ((ll)like.at(i).size() <= w.at(i)) {
      que.push(i);
      checked_dish.at(i) = true;
    }
  }
  vector<bool> done_person(m);
  vector<ll> order;
  while (!que.empty()) {
    ll i = que.front(); que.pop();
    for (ll p : like.at(i)) {
      if (done_person.at(p)) continue;
      done_person.at(p) = true;
      order.push_back(p);
      ll j = x.at(p) == i ? y.at(p) : x.at(p);
      if (!checked_dish.at(j)) {
	like.at(j).erase(p);
	if ((ll)like.at(j).size() == w.at(j)) {
	  que.push(j);
	  checked_dish.at(j) = true;
	}
      }
    }
  }
  if ((ll)order.size() == m) {
    cout << "ALIVE\n";
    for (ll i = m-1; i >= 0; i--) {
      if (i < m-1) cout << " ";
      cout << order.at(i) + 1;
    }
    cout << endl;
  }else {
    cout << "DEAD\n";
  }

  return 0;
}

