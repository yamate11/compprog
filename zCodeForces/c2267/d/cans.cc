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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, A, dec=1) [XhSEuT3L]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
    // @End [XhSEuT3L]
    
    vector<ll> divis(N);
    REP(i, 0, N) divis[A[i]] = i % 2;
    vector<ll> room(2);
    if (divis[N - 1] == 0) { room[0] = 0; room[1] = 2; }
    else                   { room[0] = 2; room[1] = 0; }
    REPrev(i, N - 2, 0) {
      ll k = divis[i];
      if (room[k] == 0) {
        cout << "NO\n";
        return ;
      }
      room[k]--;
      room[1 - k]++;
    }
    cout << "YES\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

