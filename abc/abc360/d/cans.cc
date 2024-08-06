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

  ll N, T; cin >> N >> T;
  string S; cin >> S;
  // @InpVec(N, X) [KO9atALy]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [KO9atALy]

  enum kind { IN, STAY, OUT };
  using ev_t = pair<ll, kind>;
  vector<ev_t> ev;
  REP(i, 0, N) {
    if (S[i] == '0') {
      ev.emplace_back(X[i], STAY);
    }else {
      ev.emplace_back(X[i], IN);
      ev.emplace_back(X[i] + 2 * T, OUT);
    }
  }
  sort(ALL(ev));
  ll ans = 0;
  ll cur = 0;
  for (auto [t, k] : ev) {
    if (k == IN) {
      cur++;
    }else if (k == STAY) {
      ans += cur;
    }else if (k == OUT) {
      cur--;
    }
  }
  cout << ans << endl;
  return 0;
}

