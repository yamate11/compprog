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

  map<ll, vector<ll>> mp;
  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [0ybDcji9]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [0ybDcji9]

  REP(i, 0, N) {
    mp[A[i]].push_back(i);
  }
  REP(_q, 0, Q) {
    ll x, k; cin >> x >> k; k--;
    auto& vec = mp[x];
    if (k >= ssize(vec)) {
      cout << -1 << "\n";
    }else {
      cout << vec[k] + 1 << "\n";
    }
  }

  return 0;
}

