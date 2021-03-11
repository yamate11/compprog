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

  string S; cin >> S;
  ll N; N = S.size();
  vector tbl(N + 1, vector(2, -1LL));

  auto func = [&](auto rF, ll i, ll carry) -> ll {
    if (i == N) return carry;
    ll& ret = tbl[i][carry];
    if (ret == -1) {
      ll d = S[i] - '0' + carry;
      if (d <= 9) {
	ret = min(d + rF(rF, i + 1, 0), 10 - d + rF(rF, i + 1, 1));
      }else if (d == 10) {
	ret = rF(rF, i + 1, 1);
      }
    }
    return ret;
  };
  cout << func(func, 0, 0) << endl;

  return 0;
}

