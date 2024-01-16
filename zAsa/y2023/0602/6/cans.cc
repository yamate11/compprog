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
  // @InpMVec(N, (A, B)) [nOH6bygU]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [nOH6bygU]
  vector<ll> ord(N); REP(i, 0, N) ord[i] = i;
  sort(ALL(ord),
       [&](ll i, ll j) -> bool {
         ll di = A[i] < B[i] ? -1 : A[i] == B[i] ? 0 : 1;
         ll dj = A[j] < B[j] ? -1 : A[j] == B[j] ? 0 : 1;
         if (di != dj) return di < dj;
         if (di == 0) return i < j;
         if (di == -1) return A[i] < A[j];
         if (di == 1) return B[i] > B[j];
         assert(0);
       });
  ll ans = 0;
  ll cur = 0;
  REP(i, 0, N) {
    ll j = ord[i];
    cur += A[j];
    ans = max(ans, cur);
    cur -= B[j];
  }
  cout << ans << endl;
  return 0;
}

