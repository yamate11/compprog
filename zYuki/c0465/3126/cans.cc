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

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, X) [523oYOIZ]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [523oYOIZ]

  set<ll> ss;
  vector<vector<ll>> ans;
  REP(i, 0, N) {
    ll x = X[i];
    if (ss.find(x) == ss.end()) {
      ss.insert(x);
      ans.push_back(vector<ll>{1, x, x});
      ans.push_back(vector<ll>{2, x});
    }else {
      ans.push_back(vector<ll>{2, x});
    }
  }
  if (ssize(ans) > Q) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  REP(i, 0, ssize(ans)) {
    REPOUT(j, 0, ssize(ans[i]), ans[i][j], " ");
  }
  REP(i, ssize(ans), Q) {
    cout << "1 1 1\n";
  }


  return 0;
}

