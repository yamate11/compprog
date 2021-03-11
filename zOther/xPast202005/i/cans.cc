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
  vector<ll> row(N), col(N);
  iota(row.begin(), row.end(), 0);
  iota(col.begin(), col.end(), 0);
  bool trans = false;
  ll Q; cin >> Q;
  for (ll q = 0; q < Q; q++) {
    ll t; cin >> t;
    if (t == 3) trans = !trans;
    else {
      ll a, b; cin >> a >> b; a--; b--;
      if (t == 4) {
	if (trans) swap(a, b);
	ll aa = row.at(a);
	ll bb = col.at(b);
	cout << N * aa + bb << "\n";
      }else if (t == 1) {
	if (trans) {
	  swap(col.at(a), col.at(b));
	}else {
	  swap(row.at(a), row.at(b));
	}
      }else if (t == 2) {
	if (!trans) {
	  swap(col.at(a), col.at(b));
	}else {
	  swap(row.at(a), row.at(b));
	}
      }else {
	assert(0);
      }
    }
  }
 

  return 0;
}

