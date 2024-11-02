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
  // @InpMVec(N, (T, (X, dec=1))) [Jydh7EfD]
  auto T = vector(N, ll());
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; v2 -= 1; X[i] = v2;
  }
  // @End [Jydh7EfD]

  vector stacks(N, vector<ll>());
  vector<ll> use(N, -1LL);
  REP(i, 0, N) {
    ll t = T[i];
    ll x = X[i];
    if (t == 1) {
      stacks[x].push_back(i);
      use[i] = 0;
    }else if (t == 2) {
      if (stacks[x].empty()) {
        cout << -1 << endl;
        return 0;
      }
      ll j = stacks[x].back(); stacks[x].pop_back();
      use[j] = 1;
    }
  }
  ll K = 0;
  ll k = 0;
  REP(i, 0, N) {
    k += use[i];
    K = max(K, k);
  }
  cout << K << endl;
  REP(i, 0, N) {
    if (use[i] != -1) {
      cout << use[i] << " ";
    }
  }
  cout << endl;

  return 0;
}

