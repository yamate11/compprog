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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main() {
  ll N, M; cin >> N >> M;

  // @InpVec(N, A, (char, int), dec='a') [ZIS47lWX]
  auto A = vector(N, int());
  for (int i = 0; i < N; i++) { char v; cin >> v; v -= 'a'; A[i] = v; }
  // @End [ZIS47lWX]

  // @InpVec(N, A4, base=1) [AAGASD94]
  auto A4 = vector(N + 1, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A4[i + 1] = v; }
  // @End [AAGASD94]

  // @InpGrid(N, M, A2) [t3Y2hEiF]
  auto A2 = vector(N, vector(M, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; A2[i][j] = v; }
  // @End [t3Y2hEiF]

  // @InpVec(N, A3, type=pll) [jrPrG5GH]
  auto A3 = vector(N, pll());
  for (int i = 0; i < N; i++) { pll v; cin >> v; A3[i] = v; }
  // @End [jrPrG5GH]

  // @InpVec(N, A3a, pll) [jrPrG5GH]
  auto A3a = vector(N, pll());
  for (int i = 0; i < N; i++) { pll v; cin >> v; A3a[i] = v; }
  // @End [jrPrG5GH]

  // @InpMVec(N, ((L, dec=1), R, (C, (char, bool), dec='0'))) [I5DGvw6d]
  auto L = vector(N, ll());
  auto R = vector(N, ll());
  auto C = vector(N, bool());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
    char v3; cin >> v3; v3 -= '0'; C[i] = v3;
  }
  // @End [I5DGvw6d]

  // @InpNbrList(N, M, nbr1, dec=1) [p4PEMtJH]
  auto nbr1 = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr1[u].emplace_back(v);
    nbr1[v].emplace_back(u);
  }
  // @End [p4PEMtJH]

  // @InpNbrList(N, N-1, nbr2, dec=1) [Nh9oEeGt]
  auto nbr2 = vector(N, vector(0, int()));
  for (int i = 0; i < N-1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr2[u].emplace_back(v);
    nbr2[v].emplace_back(u);
  }
  // @End [Nh9oEeGt]

  // @InpNbrList(N, N - 1, fwd, dec=1, dir=True) [52UKbPWS]
  auto fwd = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
  }
  // @End [52UKbPWS]
  
  // @InpNbrList(N, N - 1, fwd2, dec=1, bwd=back) [gk8ZeH0v]
  auto fwd2 = vector(N, vector(0, int()));
  auto bwd = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd2[u].emplace_back(v);
    bwd[v].emplace_back(u);
  }
  // @End [gk8ZeH0v]
  
  // @InpNbrList(N, M, nbr3, read=(cost, (desc, string)), idx=eid, dec=1, ord=((desc, True), (cost, True), eid)) [4td9K2Hg]
  struct nbr3_t {
    int nd;
    ll cost;
    string desc;
    int eid;
    nbr3_t() {}
    nbr3_t(int nd_, ll cost_, string desc_) : nd(nd_), cost(cost_), desc(desc_) {}
    nbr3_t(int nd_, ll cost_, string desc_, int eid_) : nd(nd_), cost(cost_), desc(desc_), eid(eid_) {}
    bool operator<(const nbr3_t& o) const {
      if (desc > o.desc) return true;
      if (cost > o.cost) return true;
      if (eid < o.eid) return true;
      return false;
    }
  };
  auto nbr3 = vector(N, vector(0, nbr3_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll cost; cin >> cost;
    string desc; cin >> desc;
    nbr3[u].emplace_back(v, cost, desc, i);
    nbr3[v].emplace_back(u, cost, desc, i);
  }
  // @End [4td9K2Hg]

}

// @DefStruct(SS, (a, b, c)) [YNs7urGy]
struct SS_t {
  ll a;
  ll b;
  ll c;
  SS_t() {}
  SS_t(ll a_, ll b_, ll c_) : a(a_), b(b_), c(c_) {}
  friend istream& operator>>(istream& istr, SS_t& t) {
    istr >> t.a >> t.b >> t.c;
    return istr;
  }
};
// @End [YNs7urGy]

// @DefStruct(SS2, (a, (c, char)), ord=((c, True), a, iii), idx=iii, istr=True) [maInp7PB]
struct SS2_t {
  ll a;
  char c;
  int iii;
  SS2_t() {}
  SS2_t(ll a_, char c_) : a(a_), c(c_) {}
  SS2_t(ll a_, char c_, int iii_) : a(a_), c(c_), iii(iii_) {}
  friend istream& operator>>(istream& istr, SS2_t& t) {
    istr >> t.a >> t.c;
    return istr;
  }
  bool operator<(const SS2_t& o) const {
    if (c > o.c) return true;
    if (a < o.a) return true;
    if (iii < o.iii) return true;
    return false;
  }
};
// @End [maInp7PB]
