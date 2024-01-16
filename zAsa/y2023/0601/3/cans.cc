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

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [ex8pBqzh]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [ex8pBqzh]
  // @InpVec(Q, X) [dhCU9kBJ]
  auto X = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; X[i] = v; }
  // @End [dhCU9kBJ]
  using ev_t = tuple<ll, ll, ll>;
  vector<ev_t> ev;
  REP(i, 0, N) ev.emplace_back(A[i], i, 0);
  REP(i, 0, Q) ev.emplace_back(X[i], i, 1);
  sort(ALL(ev));
  ll s = 0; REP(i, 0, N) s += A[i];
  ll d = -N;
  vector<ll> ans(Q);
  ll tm = 0;
  for (auto [t, i, k] : ev) {
    s += d * (t - tm);
    tm = t;
    if (k == 0) {
      d += 2;
    }else if (k == 1) {
      ans[i] = s;
    }else assert(0);
  }
  REPOUT(i, 0, Q, ans[i], "\n");

  return 0;
}

