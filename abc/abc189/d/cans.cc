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

  ll N; cin >> N;
  vector<string> S(N);
  for (ll i = 0; i < N; i++) cin >> S[i];
  vector tbl(N + 1, vector(2, 0LL));
  tbl[0][0] = 1;
  tbl[0][1] = 1;
  for (ll i = 0; i < N; i++) {
    if (S[i] == "AND") {
      tbl[i + 1][0] = tbl[i][0] * 2 + tbl[i][1];
      tbl[i + 1][1] = tbl[i][1];
    }else if (S[i] == "OR") {
      tbl[i + 1][0] = tbl[i][0];
      tbl[i + 1][1] = tbl[i][0] + tbl[i][1] * 2;
    }
  }
  cout << tbl[N][1] << endl;

  return 0;
}

