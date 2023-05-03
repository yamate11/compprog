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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K, L; cin >> N >> M >> K >> L;
  // @InpVec(N, A, dec=1) [n6pwRdXB]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [n6pwRdXB]
  // @InpVec(L, B, dec=1) [O39ckCBq]
  auto B = vector(L, ll());
  for (int i = 0; i < L; i++) { ll v; cin >> v; v -= 1; B[i] = v; }
  // @End [O39ckCBq]
  // @InpNbrList(N, M, nbr, dec=1, read=C) [pwJm9WqU]
  struct nbr_t {
    int nd;
    ll C;
    nbr_t() {}
    nbr_t(int nd_, ll C_) : nd(nd_), C(C_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [pwJm9WqU]

  ll big = 1e18;
  vector dist1(N, big);
  vector dist2(N, big);
  vector state1(N, -1LL);
  vector state2(N, -1LL);
  using sta = tuple<ll, ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  REP(i, 0, L) {
    dist1[B[i]] = 0;
    state1[B[i]] = A[B[i]];
    pque.emplace(0, B[i], A[B[i]]);
  }
  while (not pque.empty()) {
    auto [d, nd, st] = pque.top(); pque.pop();
    if (d <= dist1[nd]) {
      for (auto [peer, len] : nbr[nd]) {
        ll newD = d + len;
        if (newD < dist1[peer]) {
          dist1[peer] = newD;
          state1[peer] = st;
          pque.emplace(newD, peer, st);
        }
      }
    }
  }
  REP(nd, 0, N) {
    ll d = big;
    ll st = -1;
    for (auto [peer, len] : nbr[nd]) {
      if (state1[nd] != state1[peer]) {
        if (len + dist1[peer] < d) {
          d = len + dist1[peer];
          st = state1[peer];
        }
      }
    }
    dist2[nd] = d;
    state2[nd] = st;
    pque.emplace(d, nd, st);
  }
  while (not pque.empty()) {
    auto [d, nd, st] = pque.top(); pque.pop();
    if (d <= dist2[nd]) {
      for (auto [peer, len] : nbr[nd]) {
        if (state1[peer] == state1[nd]) {
          ll newD = d + len;
          if (newD < dist2[peer]) {
            dist2[peer] = newD;
            state2[peer] = st;
            pque.emplace(newD, peer, st);
          }
        }
      }
    }
  }
  REP(nd, 0, N) {
    if (state1[nd] == A[nd]) {
      cout << (dist2[nd] >= big ? -1 : dist2[nd]) << " ";
    }else {
      cout << (dist1[nd] >= big ? -1 : dist1[nd]) << " ";
    }
  }
  cout << endl;


  return 0;
}

