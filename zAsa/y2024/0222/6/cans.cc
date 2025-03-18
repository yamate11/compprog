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

  ll N; cin >> N;
  // @InpMVec(N, (A, B)) [5tGI6ecb]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [5tGI6ecb]

  auto cmp = [](ll x) -> int {
    if (x < 0) return -1;
    else if (x == 0) return 0;
    else if (x > 0) return 1;
    else assert(0);
  };

  vector<ll> ord(N, 0LL);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](ll i, ll j) -> bool {
    ll si = cmp(A[i] - B[i]);
    ll sj = cmp(A[j] - B[j]);
    if (si != sj) return si < sj;
    if (si == 0) return i < j;
    if (si == -1) return A[i] < A[j];
    if (si == 1) return B[i] > B[j];
    assert(0);
  });
  ll ans = 0;
  ll c = 0;
  REP(ii, 0, N) {
    ll i = ord[ii];
    ans = max(ans, c + A[i]);
    c += A[i] - B[i];
  }
  cout << ans << endl;

  return 0;
}

