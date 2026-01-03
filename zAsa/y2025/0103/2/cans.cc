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

  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  REP(i, 0, N) {
    ll p, q, r; cin >> p >> q >> r;
    A[i] = p + q + r;
  }
  auto B = A;
  sort(ALL(B));
  REP(i, 0, N) {
    ll p = B.end() - upper_bound(ALL(B), A[i] + 300);
    if (p <= K - 1) {
      cout << "Yes\n";
    }else {
      cout << "No\n";
    }
  }
  return 0;
}

