#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, Q; cin >> N >> M >> Q;
  vector score(M+1, N);
  vector tbl(N+1, vector<bool>(M+1, false));

  for (ll q = 0; q < Q; q++) {
    ll t; cin >> t;
    if (t == 1) {
      ll n; cin >> n;
      ll a = 0;
      for (ll i = 1; i <= M; i++) {
	if (tbl.at(n).at(i)) a += score.at(i);
      }
      cout << a << endl;
    }else {
      ll n, m; cin >> n >> m;
      tbl.at(n).at(m) = true;
      score.at(m)--;
    }
  }

  return 0;
}

