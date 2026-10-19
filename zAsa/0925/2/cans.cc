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

  ll N, M; cin >> N >> M;
  string S, T; cin >> S >> T;
  vector<bool> jump(N + 1, false);
  REP(i, 0, M) {
    ll l, r; cin >> l >> r; l--;
    jump[l] = not jump[l];
    jump[r] = not jump[r];
  }
  ll isT = false;
  REP(i, 0, N) {
    isT = isT ^ jump[i];
    if (isT) cout << T[i];
    else cout << S[i];
  }
  cout << "\n";

  return 0;
}

