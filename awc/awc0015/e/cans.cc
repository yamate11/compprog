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

// @@ !! LIM(mo)

// ---- inserted library file mo.cc

struct Mo {
  using vq_t = tuple<int, int, int>;
  int size;
  int vq_idx;
  vector<vq_t> vq;
  int cl;
  int cr;

  Mo(int size_) : size(size_), vq_idx(0), vq(), cl(0), cr(0) {}
  void add_query(int l, int r) { vq.emplace_back(l, r, vq_idx++); }

  void run(auto in_left, auto in_right, auto out_left, auto out_right, auto calc) {
    int qsz = vq.size();
    int bsize = max(1, int((double)size / sqrt(qsz)));
    cl = 0;
    cr = 0;
    sort(vq.begin(), vq.end(),
         [&](const vq_t& p1, const vq_t& p2) -> bool {
           const auto& [a1, b1, i1] = p1;
           const auto& [a2, b2, i2] = p2;
           int z1 = a1 / bsize;
           int z2 = a2 / bsize;
           if (z1 != z2) return z1 < z2;
           else if (z1 % 2 == 0) return b1 < b2;
           else return b1 > b2;
         });
    for (const auto& [l, r, i] : vq) {
      // in_* must be called before out_*
      while (l < cl)   in_left(--cl);
      while (cr < r)  in_right(cr++);
      while (cl < l)  out_left(cl++);
      while (r < cr) out_right(--cr);
      calc(i);
    }
  }

  void run(auto f_in, auto f_out, auto calc) { return run(f_in, f_in, f_out, f_out, calc); }

};

// ---- end mo.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, P, dec=1) [vDKaSJJ1]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [vDKaSJJ1]

  vector<ll> nxt(N);
  vector<ll> prv(N);

  {
    vector<ll> pos(N, -1LL);
    REP(i, 0, N) {
      prv[i] = pos[P[i]];
      pos[P[i]] = i;
    }
    pos = vector<ll>(N, N);
    REPrev(i, N - 1, 0) {
      nxt[i] = pos[P[i]];
      pos[P[i]] = i;
    }
  }
  
  Mo mo(N);
  REP(i, 0, Q) {
    ll l, r; cin >> l >> r; l--;
    mo.add_query(l, r);
  }
  ll val = 0;
  vector<ll> ans(Q);
  auto in_left = [&](ll x) -> void {
    if (mo.cr <= nxt[x]) val++;
  };
  auto in_right = [&](ll x) -> void {
    if (prv[x] < mo.cl) val++;
  };
  auto out_left = [&](ll x) -> void {
    if (mo.cr <= nxt[x]) val--;
  };
  auto out_right = [&](ll x) -> void {
    if (prv[x] < mo.cl) val--;
  };
  auto calc = [&](ll q) -> void { ans[q] = val; };
  mo.run(in_left, in_right, out_left, out_right, calc);
  REPOUT(q, 0, Q, ans[q], "\n");



  return 0;
}

