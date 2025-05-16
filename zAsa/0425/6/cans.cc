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

  ll N, Q; cin >> N >> Q;
  // @InpMVec(N, (S, T, X)) [XYhF3JM5]
  auto S = vector(N, ll());
  auto T = vector(N, ll());
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; S[i] = v1;
    ll v2; cin >> v2; T[i] = v2;
    ll v3; cin >> v3; X[i] = v3;
  }
  // @End [XYhF3JM5]
  // @InpVec(Q, D) [19wy10cs]
  auto D = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; D[i] = v; }
  // @End [19wy10cs]

  enum Kind { CEND, CSTART, PERSON };
  using ev_t = tuple<ll, Kind, ll>;
  vector<ev_t> ev;
  REP(i, 0, N) {
    ev.emplace_back(S[i] - X[i], CSTART, X[i]);
    ev.emplace_back(T[i] - X[i], CEND, X[i]);
  }
  REP(i, 0, Q) {
    ev.emplace_back(D[i], PERSON, i);
  }
  sort(ALL(ev));
  vector<ll> ans(Q);
  set<ll> A;
  for (auto [t, kd, x] : ev) {
    if (kd == CEND) {
      A.erase(x);
    }else if (kd == CSTART) {
      A.insert(x);
    }else if (kd == PERSON) {
      if (A.empty()) {
        ans[x] = -1;
      }else {
        ans[x] = *A.begin();
      }
    }
  }
  REPOUT(i, 0, Q, ans[i], "\n");

  return 0;
}

