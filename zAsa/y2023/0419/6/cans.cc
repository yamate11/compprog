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

// @@ !! LIM(mo)

// ---- inserted library file mo.cc

struct Mo {
  using vq_t = tuple<int, int, int>;
  int size;
  int vq_idx;
  vector<vq_t> vq;

  Mo(int size_) : size(size_), vq_idx(0), vq() {}
  void add_query(int l, int r) { vq.emplace_back(l, r, vq_idx++); }

  void run(auto in_left, auto in_right, auto out_left, auto out_right, auto calc) {
    int qsz = vq.size();
    int bsize = max(1, int((double)size / sqrt(qsz)));
    int cl = 0, cr = 0;
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
      while (l < cl)   in_left(--cl);
      while (cl < l)  out_left(cl++);
      while (cr < r)  in_right(cr++);
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

  ll N; cin >> N;
  // @InpVec(N, A, dec=1) [3AmdJOcA]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [3AmdJOcA]
  ll Q; cin >> Q;
  // @InpMVec(Q, (L, R)) [DAz81lNO]
  auto L = vector(Q, ll());
  auto R = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; L[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
  }
  // @End [DAz81lNO]

  Mo mo(N);
  REP(i, 0, Q) mo.add_query(L[i] - 1, R[i]);
  vector<ll> cnt(N);
  ll cans = 0;
  vector<ll> ans(Q);
  auto f_in  = [&](ll i) -> void { if (++cnt[A[i]] % 2 == 0) cans++; };
  auto f_out = [&](ll i) -> void { if (cnt[A[i]]-- % 2 == 0) cans--; };
  auto calc = [&](ll i) -> void { ans[i] = cans; };
  mo.run(f_in, f_out, calc);
  REPOUT(i, 0, Q, ans[i], "\n");

  return 0;
}

