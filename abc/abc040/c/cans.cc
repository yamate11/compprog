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
  vector<ll> A;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    A.push_back(a);
  }
  vector<ll> tbl(N, LLONG_MAX);
  tbl.at(0) = 0;
  for (ll i = 0; i < N-1; i++) {
    tbl.at(i+1) = min(tbl.at(i+1), tbl.at(i) + abs(A.at(i+1) - A.at(i)));
    if (i+2 < N) tbl.at(i+2) = min(tbl.at(i+2), tbl.at(i) + abs(A.at(i+2) - A.at(i)));
  }
  cout << tbl.at(N-1) << endl;

  return 0;
}

