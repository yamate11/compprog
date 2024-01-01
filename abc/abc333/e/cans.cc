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

  ll N; cin >> N;
  // @InpMVec(N, (T, (X, dec=1))) [KXEXgdf7]
  auto T = vector(N, ll());
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; v2 -= 1; X[i] = v2;
  }
  // @End [KXEXgdf7]

  vector rec(N, vector<ll>());
  REP(i, 0, N) {
    if (T[i] == 1) rec[X[i]].push_back(i);
  }
  vector pick(N, false);
  REPrev(i, N - 1, 0) {
    if (T[i] == 2) {
      auto& rr = rec[X[i]];
      while (not rr.empty() and rr.back() > i) rr.pop_back();
      if (rr.empty()) {
        cout << -1 << endl;
        return 0;
      }
      ll j = rr.back(); rr.pop_back();
      pick[j] = true;
    }
  }
  ll K = 0;
  ll cur = 0;
  vector<ll> ans;
  REP(i, 0, N) {
    if (T[i] == 1) {
      if (pick[i]) {
        cur++;
        ans.push_back(1);
      }else {
        ans.push_back(0);
      }
    }else if (T[i] == 2) {
      cur--;
    }else assert(0);
    K = max(K, cur);
  }
  cout << K << endl;
  REPOUT(i, 0, SIZE(ans), ans[i], " ");

  return 0;
}

