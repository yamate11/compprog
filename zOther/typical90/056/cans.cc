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

  ll N, S; cin >> N >> S;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) cin >> A[i] >> B[i];
  auto tbl = vector(N + 1, vector(S + 1, false));
  tbl[0][0] = true;
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j <= S; j++) {
      if (tbl[i][j]) {
        if (j + A[i] <= S) tbl[i + 1][j + A[i]] = true;
        if (j + B[i] <= S) tbl[i + 1][j + B[i]] = true;
      }
    }
  }
  string rec;
  if (tbl[N][S]) {
    ll t = S;
    for (ll i = N - 1; i >= 0; i--) {
      ll x;
      if (t - A[i] >= 0 && tbl[i][t - A[i]]) {
        x = A[i];
        rec += 'A';
      }else if (t - B[i] >= 0 && tbl[i][t - B[i]]) {
        x = B[i];
        rec += 'B';
      } else assert(0);
      t -= x;
    }
    reverse(rec.begin(), rec.end());
    cout << rec << endl;
  }else {
    cout << "Impossible\n";
  }

  return 0;
}

