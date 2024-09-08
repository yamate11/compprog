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

int main() {
  ll N; cin >> N;
  vector<ll> A(N), B(N);
  REP(i, 0, N) cin >> A[i];
  REP(i, 0, N) {
    ll b; cin >> b;
    A[i] -= b;
  }
  sort(ALL(A));
  vector<ll> Sum(N + 1);
  REP(i, 0, N) Sum[i + 1] = Sum[i] + A[i];
  if (Sum[N] < 0) {
    cout << -1 << endl;
  }else {
    ll numNeg = lower_bound(ALL(A), 0LL) - A.begin();
    ll cover = Sum.end() - upper_bound(ALL(Sum), Sum[N] + Sum[numNeg]);
    cout << numNeg + cover << endl;
  }
  return 0;
}

