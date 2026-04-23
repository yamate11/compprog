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

  ll M, S; cin >> M >> S;
  // @InpVec(M, B) [OrChMSRw]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [OrChMSRw]

  ll a = S / M;
  ll b = S % M;
  REP(i, 0, M) {
    B[i] += a;
    if (i < b) B[i]++;
  }
  vector<ll> C(M + 1, 0LL);
  REP(i, 0, M) C[i + 1] = C[i] + B[i];

  ll N; cin >> N;
  REP(_q, 0, N) {
    ll l, r; cin >> l >> r; l--;
    cout << C[r] - C[l] << "\n";
  }

  return 0;
}

