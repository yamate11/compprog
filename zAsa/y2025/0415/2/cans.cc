#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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

  ll N, Q; cin >> N >> Q;
  string S; cin >> S;
  vector<ll> A(N - 1);
  REP(i, 0, N - 1) A[i] = S[i] == S[i + 1];
  vector<ll> B(N);
  REP(i, 0, N - 1) B[i + 1] = B[i] + A[i];
  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r; l--;
    cout << B[r - 1] - B[l] << "\n";
  }

  return 0;
}

