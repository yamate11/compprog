#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <atcoder/lazysegtree>
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define InpVec(vec, n) vector<ll> vec(n); REP(i, 0, (n)) cin >> vec[i]
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

constexpr ll inf = 1e18;
using S = ll;
using F = ll;
S op(S a, S b) { return min(a, b); }
constexpr S e() { return inf; }
S mapping(F f, S x) { return min(f, x); }
F composition(F f, F g) { return min(f, g); }
constexpr F id() { return inf; }
using Seg = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
  ll N, M; cin >> N >> M;
  vector<tuple<ll, ll, ll>> LRC;
  for (ll i = 0; i < M; i++) {
    ll l, r, c; cin >> l >> r >> c; l--;
    LRC.emplace_back(l, r, c);
  }
  sort(ALL(LRC));

  Seg st(N);
  st.set(0, 0);
  for (auto [l, r, c] : LRC) st.apply(l, r, st.get(l) + c);
  ll ans = st.get(N - 1);
  cout << (ans >= inf ? -1 : ans) << endl;

  return 0;
}

