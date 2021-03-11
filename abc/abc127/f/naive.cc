#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll Q;
vector<ll> p;
vector<ll> q;

void update(ll idx) {
  cin >> p.at(idx) >> q.at(idx);
}

ll getV(ll idx, ll x) {
  ll sum = 0;
  for (ll k = 0; k < idx; k++) {
    sum += abs(x - p.at(k)) + q.at(k);
  }
  return sum;
}

void query(ll idx) {
  ll resX = 0;
  ll resF = (ll)(1e14);
  for (ll j = 0; j < idx; j++) {
    ll y = getV(idx, p.at(j));
    if (y < resF || (y == resF && p.at(j) < resX))  {
      resX = p.at(j);
      resF = y;
    }
  }
  cout << resX << " " << resF << endl;
}

int main() {
  cin >> Q;
  
  p.resize(Q);
  q.resize(Q);
  ll idx = 0;
  for (ll i = 0; i < Q; i++) {
    ll t;
    cin >> t;
    if (t == 1)  update(idx++);
    if (t == 2)  query(idx);
  }

}
