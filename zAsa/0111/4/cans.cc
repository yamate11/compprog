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

  ll N, C; cin >> N >> C;
  // @InpMVec(N, (A, B, vecC)) [5wkKcVO1]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  auto vecC = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
    ll v3; cin >> v3; vecC[i] = v3;
  }
  // @End [5wkKcVO1]

  enum KIND { START, END };
  using ev_t = tuple<ll, KIND, ll>;
  vector<ev_t> ev;
  REP(i, 0, N) {
    ev.emplace_back(A[i], START, i);
    ev.emplace_back(B[i] + 1, END, i);
  }
  sort(ALL(ev));
  ll ans = 0;
  ll cur = 0;
  ll prev_date = -1;
  for (auto [dt, kd, idx] : ev) {
    ans += min(C, cur) * (dt - prev_date);
    if (kd == START) cur += vecC[idx];
    else             cur -= vecC[idx];
    prev_date = dt;
  }
  cout << ans << endl;

  return 0;
}

