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

  ll N, M, X1; cin >> N >> M >> X1;
  // @InpMVec(M, ((A, dec=1), (B, dec=1), S, T)) [KtN59K7l]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  auto S = vector(M, ll());
  auto T = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    ll v3; cin >> v3; S[i] = v3;
    ll v4; cin >> v4; T[i] = v4;
  }
  // @End [KtN59K7l]

  vector X(M, 0LL);
  X[0] = X1;
  vector wait(N, -1LL);
  enum kind { WAIT, ARRIVE, DEPART};
  using ev_t = tuple<ll, kind, ll>;
    /*
  struct ev_t {
    ll time;
    kind kd;
    ll aux;
  };
    */
  priority_queue<ev_t, vector<ev_t>, greater<ev_t>> ev;
  REP(i, 0, M) {
    ev.emplace(S[i], DEPART, i);
    ev.emplace(T[i], ARRIVE, i);
  }
  while (not ev.empty()) {
    auto e = ev.top(); ev.pop();
    auto [tm, kd, ax] = e;
    if (kd == WAIT) {
      wait[ax] = -1;
    }else if (kd == ARRIVE) {
      ll station = B[ax];
      if (X[ax] > 0) {
        ll t0 = tm + X[ax];
        if (wait[station] < t0) wait[station] = t0;
      }
    }else if (kd == DEPART) {
      ll station = A[ax];
      if (wait[station] > tm) {
        X[ax] = wait[station] - tm;
      }
    }
  }
  REPOUT(i, 1, M, X[i], " ");

  return 0;
}

