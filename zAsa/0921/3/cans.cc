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
  auto T = vector(N, 0LL);
  auto A = vector(N, vector<ll>());
  REP(i, 0, N) {
    cin >> T[i];
    ll k; cin >> k;
    REP(j, 0, k) {
      ll a; cin >> a; a--;
      A[i].push_back(a);
    }
  }
  ll ans = 0;
  auto X = vector(N, 0LL);
  auto st = vector<ll>();
  X[N - 1] = T[N - 1];
  ans += X[N - 1];
  st.push_back(N - 1);
  while (not st.empty()) {
    ll i = st.back(); st.pop_back();
    for (ll j : A[i]) {
      if (X[j] > 0) continue;
      X[j] = T[j];
      ans += X[j];
      st.push_back(j);
    }
  }
  cout << ans << endl;

  return 0;
}

