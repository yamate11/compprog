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
  ll M = 1LL << N;
  ll p = K / M;
  ll q = K % M;
  ll U = (q == 0) ? 0 : 1;
  
  vector<ll> vec{0};
  REP(i, 0, N) {
    auto prev = move(vec);
    vec = vector<ll>(ssize(prev) * 2);
    REP(j, 0, ssize(prev)) {
      vec[2 * j] = prev[j];
      vec[2 * j + 1] = prev[j] + ssize(prev);
    }
  }
  vector<ll> Rvec(ssize(vec));
  REP(i, 0, ssize(vec)) Rvec[vec[i]] = i;
  
  vector<ll> ans(M, p);
  REP(i, 0, q) ans[Rvec[i]]++;
  cout << U << "\n";
  REPOUT(i, 0, M, ans[i], " ");
  

  return 0;
}

