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
  // @InpVec(N, A) [aQiEOzFl]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [aQiEOzFl]

  ll sz = 1e5;
  vector<ll> cnt(sz + 1);
  REP(i, 0, N) cnt[A[i]]++;
  ll ecnt = 0;
  ll acnt = 0;
  REP(i, 0, sz + 1) {
    if (cnt[i] > 0) {
      acnt++;
      if (cnt[i] % 2 == 0) ecnt++;
    }
  }
  if (ecnt % 2 == 0) {
    cout << acnt << endl;
  }else {
    cout << acnt - 1 << endl;
  }

  return 0;
}

