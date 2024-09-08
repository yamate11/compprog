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
  // @InpMVec(N, (A, B)) [jU2F2aaZ]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [jU2F2aaZ]

  enum kind { START, END };
  using ev_t = pair<ll, kind>;
  vector<ev_t> ev;
  REP(i, 0, N) {
    ev.emplace_back(A[i], START);
    ev.emplace_back(B[i], END);
  }
  sort(ALL(ev));

  ll cur = 0;
  ll ans = 0;
  for (auto [t, k] : ev) {
    if (k == START) cur++;
    else cur--;
    ans = max(ans, cur);
  }
  cout << ans << endl;

  return 0;
}

