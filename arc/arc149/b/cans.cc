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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [iZdNZfY0]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [iZdNZfY0]
  // @InpVec(N, B) [3mGxRa25]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [3mGxRa25]
  vector<ll> ord(N);
  REP(i, 0, N) ord[i] = i;
  sort(ALL(ord), [&](ll i, ll j) -> bool { return A[i] < A[j]; });
  vector<ll> vec;
  REP(i, 0, N) {
    ll j = B[ord[i]];
    ll idx = lower_bound(ALL(vec), j) - vec.begin();
    if (idx == SIZE(vec)) vec.push_back(j);
    else vec[idx] = j;
  }
  cout << N + SIZE(vec) << endl;

  return 0;
}

