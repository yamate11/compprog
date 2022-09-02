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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

// @DefStruct(A, (H, W, N), ord=(N), idx=idx) [VDwKfkt3]
struct A_t {
  ll H;
  ll W;
  ll N;
  int idx;
  A_t() {}
  A_t(ll H_, ll W_, ll N_) : H(H_), W(W_), N(N_) {}
  A_t(ll H_, ll W_, ll N_, int idx_) : H(H_), W(W_), N(N_), idx(idx_) {}
  friend istream& operator>>(istream& istr, A_t& t) {
    istr >> t.H >> t.W >> t.N; t.H--; t.W--;
    return istr;
  }
  bool operator<(const A_t& o) const {
    if (N > o.N) return true;
    return false;
  }
};
// @End [VDwKfkt3]

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, N; cin >> H >> W >> N;

  //@InpVec(N, A, type=A_t) [fWWXRPkC]
  auto A = vector(N, A_t());
  for (int i = 0; i < N; i++) { A_t v; cin >> v; A[i] = v; A[i].idx = i; }
  // @End [fWWXRPkC]
  sort(ALL(A));
  vector<ll> vH(H, -1);
  vector<ll> vW(W, -1);
  vector<ll> ans(N);
  map<ll, ll> addH;
  map<ll, ll> addW;
  ll prev = 1e15;
  for (auto [h, w, n, i] : A) {
    if (prev != n) {
      for (auto [hh, c] : addH) { vH[hh] = max(vH[hh], c); }
      for (auto [ww, c] : addW) { vW[ww] = max(vW[ww], c); }
      addH = map<ll, ll>();
      addW = map<ll, ll>();
      prev = n;
    }

    ll v = max(vH[h], vW[w]) + 1;
    ans[i] = v;
    addH[h] = max(addH[h], v);
    addW[w] = max(addW[w], v);
  }
  REP(i, 0, N) cout << ans[i] << "\n";
  

  return 0;
}

