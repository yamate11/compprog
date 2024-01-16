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

  ll N, M, K; cin >> N >> M >> K;
  // @InpVec(N, A) [FzygZjFd]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [FzygZjFd]
  multiset<ll> ps;
  multiset<ll> qs;
  ll sum = 0;
  vector<ll> ans;
  vector<ll> tmp;
  REP(i, 0, M) tmp.push_back(A[i]);
  sort(ALL(tmp));
  REP(i, 0, K) {
    sum += tmp[i];
    ps.insert(tmp[i]);
  }
  REP(i, K, M) {
    qs.insert(tmp[i]);
  }
  ans.push_back(sum);
  REP(i, M, N) {
    auto it = prev(ps.end());
    ll vmax = *it;
    if (vmax <= A[i]) {
      qs.insert(A[i]);
    }else {
      qs.insert(vmax);
      sum -= vmax;
      ps.erase(it);
      sum += A[i];
      ps.insert(A[i]);
    }
    auto it2 = ps.find(A[i - M]);
    if (it2 == ps.end()) {
      auto it3 = qs.find(A[i - M]);
      qs.erase(it3);
    }else {
      ps.erase(it2);
      sum -= A[i - M];
      auto it3 = qs.begin();
      ps.insert(*it3);
      sum += *it3;
      qs.erase(it3);
    }
    ans.push_back(sum);
  }
  REPOUT(i, 0, N - M + 1, ans[i], " ");

  return 0;
}

