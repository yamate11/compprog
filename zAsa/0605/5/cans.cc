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

// @@ !! LIM(input forall)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// @@ !! LIM -- end mark --

/* vector with size N of elements from 0 to LIM -1 */
template<size_t LIM, size_t N>
struct SmallVec {
  static constexpr size_t WIDTH = bit_width(LIM - 1);
  bitset<WIDTH * N> bs;
  SmallVec() {}
  SmallVec(size_t x) {
    for (size_t i = 0; i < N; i++) set(i, x);
  }
  /*
  SmallVec(const SmallVec& o) : bs(o.bs) {}
  SmallVec(SmallVec&& o) : bs(move(o.bs)) {}
  */
  bool operator==(const SmallVec& o) const { return bs == o.bs; }
  bool operator!=(const SmallVec& o) const { return not (*this == o); }
  void set(size_t i, size_t x) {
    for (size_t j = 0; j < WIDTH; j++) bs[i * WIDTH + j] = x >> j & 1;
  }
  size_t at(size_t i) {
    size_t ret = 0;
    for (size_t j = 0; j < WIDTH; j++) ret |= bs[i * WIDTH + j] << j;
    return ret;
  }
};
namespace std {
  template<size_t LIM, size_t N>
  struct hash<SmallVec<LIM, N>> {
    std::size_t operator()(const SmallVec<LIM, N>& sv) const {
      return hash<std::bitset<std::bit_width(LIM - 1) * N>>{}(sv.bs);
    }
  };
}

template<size_t LIM, size_t N>
struct SmallVec1 {
  static constexpr size_t WIDTH = bit_width(LIM - 1);
  u64 bits;
  SmallVec1() : bits(0) {}
  SmallVec1(size_t x) {
    bits = 0;
    for (size_t i = 0; i < N; i++) set(i, x);
  }
  bool operator==(const SmallVec1& o) const { return bits == o.bits; }
  bool operator!=(const SmallVec1& o) const { return not (*this == o); }
  void set(size_t i, size_t x) {
    u64 mask = ((1ULL << WIDTH) - 1) << (i * WIDTH);
    bits = (bits & ~mask) | (x << (i * WIDTH));
  }
  size_t at(size_t i) {
    u64 mask = ((1ULL << WIDTH) - 1) << (i * WIDTH);
    return (bits & mask) >> (i * WIDTH);
  }
};
namespace std {
  template<size_t LIM, size_t N>
  struct hash<SmallVec1<LIM, N>> {
    std::size_t operator()(const SmallVec1<LIM, N>& sv) const {
      return hash<u64>{}(sv.bits);
    }
  };
}


using SV = SmallVec1<9, 9>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll M; cin >> M;
  // @InpNbrList(9, M, nbr, dec=1) [nXHmPVcm]
  auto nbr = vector(9, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [nXHmPVcm]
  // @InpVec(8, P, dec=1) [pjY5OMMd]
  auto P = vector(8, ll());
  for (int i = 0; i < 8; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [pjY5OMMd]
  
  size_t NOP = 8;
  SV b0(NOP);
  REP(i, 0, 8) b0.set(P[i], i);

  size_t vac0 = EXFIND(i, 0, 9, b0.at(i) == NOP);

  SV goal(NOP);
  REP(i, 0, 8) goal.set(i, i);

  unordered_set<SV> visited;
  using sta = tuple<SV, size_t, size_t>;
  queue<sta> que;
  visited.insert(b0);
  que.emplace(b0, vac0, 0);
  if (b0 == goal) {
    cout << 0 << endl;
    return 0;
  }

  while (not que.empty()) {
    auto [b, vac, len] = que.front(); que.pop();
    for (size_t peer : nbr[vac]) {
      SV new_b(b);
      new_b.set(vac, b.at(peer));
      new_b.set(peer, b.at(vac));
      if (new_b == goal) {
        cout << len + 1 << "\n";
        return 0;
      }
      if (not visited.contains(new_b)) {
        visited.insert(new_b);
        que.emplace(new_b, peer, len + 1);
      }
    }
  }
  cout << -1 << endl;

  return 0;
}

