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

  ll N, M; cin >> N >> M;
  vector<ll> s;
  // @InpVec(M, A) [mprEwdL9]
  auto A = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; A[i] = v; }
  // @End [mprEwdL9]
  vector<ll> ans;
  ll idx = 0;
  REP(i, 1, N + 1) {
    if (idx < M and A[idx] == i) {
      s.push_back(i);
      idx++;
    }else {
      ans.push_back(i);
      while (not s.empty()) {
        ll t = s.back(); s.pop_back();
        ans.push_back(t);
      }
    }
  }
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

