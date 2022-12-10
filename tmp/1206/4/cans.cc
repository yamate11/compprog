#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  if (M < 2 * N or 4 * N < M) {
    cout << "-1 -1 -1\n";
  }else if (2 * N <= M and M <= 3 * N) {
    ll d = M - 2 * N;
    cout << N - d << " " << d << " " << 0 << endl;
  }else {
    ll d = M - 3 * N;
    cout << 0 << " " << N - d << " " << d << endl;
  }

  return 0;
}

