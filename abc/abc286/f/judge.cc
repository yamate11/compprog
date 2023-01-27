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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll M; cin >> M;
  vector<ll> A(M + 1), B(M + 1);
  REP(i, 1, M + 1) cin >> A[i];
  REP(i, 1, M + 1) {
    ll x = i;
    REP(j, 0, N) {
      x = A[x];
    }
    B[i] = x;
  }
  REP(i, 1, M + 1) cout << B[i] << " ";
  cout << endl;
  ll z; cin >> z;
  if (z == N) {
    cout << "# OK\n";
  }else {
    cout << "# NG\n";
  }

  return 0;
}

