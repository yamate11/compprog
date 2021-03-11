#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> A, B;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    A.push_back(a);
    B.push_back(b);
  }
  vector<ll> C, D;
  for (ll i = 0; i < M; i++) {
    ll c, d; cin >> c >> d;
    C.push_back(c);
    D.push_back(d);
  }
  for (ll i = 0; i < N; i++) {
    ll x = -1;
    ll d = LLONG_MAX;
    for (ll j = 0; j < M; j++) {
      ll dd = abs(A.at(i) - C.at(j)) + abs(B.at(i) - D.at(j));
      if (dd < d) {
	d = dd;
	x = j;
      }
    }
    cout << x+1 << endl;
  }
  

  return 0;
}

