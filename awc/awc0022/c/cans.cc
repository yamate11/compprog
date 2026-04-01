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

  ll N, M, K, T; cin >> N >> M >> K >> T;
  vector<ll> A(N, 0LL);
  REP(i, 0, M) {
    ll b; cin >> b; b--;
    A[b] = 1;
  }
  vector<ll> S(N + 1, 0LL);
  REP(i, 0, N) S[i + 1] = S[i] + A[i];
  REP(i, 0, K) {
    ll l, r; cin >> l >> r; l--;
    if (S[r] - S[l] >= T) { cout << "YES\n"; }
    else { cout << "NO\n"; }
  }

  return 0;
}

