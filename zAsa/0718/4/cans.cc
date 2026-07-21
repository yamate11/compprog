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

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((A, dec=1), (B, dec=1))) [CZPr8n9E]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [CZPr8n9E]
  ll oth = 0;
  if (N % 2 == 0) {
    vector<ll> G(N / 2);
    vector<ll> H(N / 2);
    REP(i, 0, M) {
      ll d = B[i] - A[i];
      if (d % 2 != 0) {
        ll j = A[i] + d / 2;
        j = j % (N / 2);
        G[j]++;
      }else {
        ll j = A[i] + (d - 2) / 2;
        j = j % (N / 2);
        H[j]++;
      }
    }
    REP(i, 0, N / 2) {
      oth += G[i] * (G[i] - 1) / 2;
      oth += H[i] * (H[i] - 1) / 2;
    }
  }else {
    vector<ll> G(N);
    REP(i, 0, M) {
      ll d = B[i] - A[i];
      if (d % 2 != 0) {
        ll j = A[i] + d / 2;
          G[j]++;
      }else {
        d = A[i] + N - B[i];
        ll j = B[i] + d / 2;
        j = j % N;
        G[j]++;
      }
    }
    REP(i, 0, N) oth += G[i] * (G[i] - 1) / 2;
  }
  ll ans = M * (M - 1) / 2 - oth;
  cout << ans;

  return 0;
}

