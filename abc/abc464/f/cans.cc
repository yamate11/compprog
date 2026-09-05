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

  ll N, X; cin >> N >> X;
  // @InpVec(N, A) [fhQ4tgUa]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [fhQ4tgUa]

  if (N == 1) {
    cout << A[0] << "\n";
    return 0;
  }

  ll H1 = N / 2;
  ll H2 = N - H1;
  ll sz1 = 1LL << H1;
  vector B(H1, vector(H1 + 1, vector<ll>()));
  vector C(H1 + 1, vector<ll>());
  REP(x, 0, sz1) {
    ll n = popcount((u64)x);
    ll v = 0;
    REP(i, 0, H1) if (x >> i & 1) v += A[i];
    REP(i, 0, H1) if (not (x >> i & 1)) B[i][n].push_back(v);
    C[n].push_back(v);
  }
  REP(i, 0, H1) REP(n, 0, H1 + 1) ranges::sort(B[i][n], greater<ll>());
  REP(n, 0, H1 + 1) ranges::sort(C[n], greater<ll>());

  ll sz2 = 1LL << H2;
  REP(y, 0, sz2) {
    ll m = popcount((u64)y);
    ll w = 0;
    REP(i, 0, H2) if (y >> i & 1) w += A[H1 + i];
    REP(n, 0, H1 + 1) {
      ll cnt = ranges::lower_bound(C[n], X - w - 1) - C[n].begin();
      REP(i, 0, H2) if (not (y >> i & 1)) {
        ans[H1 + i][n + m] += cnt;
      }
    }
    REP(n, 0, H1 + 1) {
      REP(i, 0, H1) {
        ll cnt = ranges::lower_bound(B[i][n], X - w - 1) - B[i][n].begin();
        ans[i][n + m] += cnt;
      }
    }


    ll k = ranges::lower_bound(C
    REP(i, 0, H2) if (not (y >> i & 1)) D[k][H1 + i]
  }

  return 0;
}

