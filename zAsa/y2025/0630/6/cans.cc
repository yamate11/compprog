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

  ll N, M, S; cin >> N >> M >> S;
  // @InpVec(N, A) [N7sQm8Yj]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [N7sQm8Yj]

  reverse(ALL(A));
  vector<ll> B(N + 1);
  REP(i, 0, N) B[i + 1] = B[i] + A[i];
  using sta = pair<ll, double>;
  vector<sta> rec;
  rec.emplace_back(1, 1e18);
  REP(i, 0, N) {
    ll len = 1;
    double val = A[i];
    while (rec.back().second < val) {
      auto [l, v] = rec.back(); rec.pop_back();
      val = (val * len + v * l) / (len + l);
      len = len + l;
    }
    rec.emplace_back(len, val);
  }
  
  double score = 0;
  REP(j, 1, ssize(rec)) {
    auto [len, val] = rec[j];
    if (S <= M * len) {
      score += S * val;
      break;
    }
    score += M * val * len;
    S -= M * len;
  }
  cout << score << endl;


  return 0;
}

