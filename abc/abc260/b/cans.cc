#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X, Y, Z; cin >> N >> X >> Y >> Z;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> B(N); REP(i, N) cin >> B[i];
  vector<bool> passed(N);
  vector<ll> C1(N); REP(i, N) C1[i] = i;
  auto C2 = C1;
  auto C3 = C1;
  sort(ALL(C1), [&](ll x, ll y) -> bool {
    if (A[x] != A[y]) return A[x] > A[y];
    else return x < y;
  });
  sort(ALL(C2), [&](ll x, ll y) -> bool {
    if (B[x] != B[y]) return B[x] > B[y];
    else return x < y;
  });
  sort(ALL(C3), [&](ll x, ll y) -> bool {
    if (A[x] + B[x] != A[y] + B[y]) return A[x] + B[x] > A[y] + B[y];
    else return x < y;
  });
  ll cnt = 0;
  REP(i, N) {
    if (cnt >= X) break;
    ll j = C1[i];
    if (not passed[j]) {
      passed[j] = true;
      cnt++;
    }
  }
  cnt = 0;
  REP(i, N) {
    if (cnt >= Y) break;
    ll j = C2[i];
    if (not passed[j]) {
      passed[j] = true;
      cnt++;
    }
  }
  cnt = 0;
  REP(i, N) {
    if (cnt >= Z) break;
    ll j = C3[i];
    if (not passed[j]) {
      passed[j] = true;
      cnt++;
    }
  }
  REP(i, N) {
    if (passed[i]) cout << i + 1 << "\n";
  }

  return 0;
}

