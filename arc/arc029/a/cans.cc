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
  vector<ll> t(4);
  for (ll i = 0; i < N; i++) cin >> t.at(i);
  ll tot = LLONG_MAX;
  for (ll s1 = 0; s1 < 2; s1++) {
    vector<ll> v1(2);
    v1.at(s1) += t.at(0);
    for (ll s2 = 0; s2 < 2; s2++) {
      vector<ll> v2(v1);
      v2.at(s2) += t.at(1);
      for (ll s3 = 0; s3 < 2; s3++) {
	vector<ll> v3(v2);
	v3.at(s3) += t.at(2);
	for (ll s4 = 0; s4 < 2; s4++) {
	  vector<ll> v4(v3);
	  v4.at(s4) += t.at(3);
	  ll cost = max(v4.at(0), v4.at(1));
	  tot = min(tot, cost);
	}
      }
    }
  }
  cout << tot << endl;

  return 0;
}

