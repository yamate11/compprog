#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"


using vl = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

// @@ !! LIM(debug bridge UnionFind)

random_device rd;
mt19937 rng(rd());
ll randrange(ll i, ll j) {
  uniform_int_distribution<ll> dist(i, j - 1);
  return dist(rng);
};

void test1() {
  articulation au(10);
  au.add_edge(0, 1);
  au.add_edge(1, 2);
  au.add_edge(1, 6);
  au.add_edge(2, 3);
  au.add_edge(2, 4);
  au.add_edge(2, 5);
  au.add_edge(6, 7);
  au.add_edge(6, 8);
  au.add_edge(8, 9);
  au.add_edge(5, 1);
  au.add_edge(8, 1);
  au.add_edge(9, 0);

  au.build();

  assert(au.llk._ord == (vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
  assert(au.llk._low == (vector<int>{0, 0, 1, 3, 4, 1, 0, 7, 0, 0}));
  assert(au._bcc == (vector<vector<int>>{{0, 1, 6, 8, 9}, {6, 7}, {1, 2, 5}, {2, 4}, {2, 3}}));
  DLOGK(au.art_seq);
  articulation::bctree* abc = au.make_bctree();
  DLOGK(abc->arts);
  auto show = [&](int a) -> void {
    auto [a1, a2] = abc->what(a);
    if (a1 == articulation::BLOCK) {
      DLOGKL("  BLOCK: ", au._bcc[a2]);
    }else {
      DLOGKL("  CUT: ", a2);
    }
  };
  for (auto [a, b] : abc->edges()) {
    show(a);
    show(b);
  }
}

void test2() {
  bridge bu(10);
  bu.add_edge(0, 1);
  bu.add_edge(1, 2);
  bu.add_edge(1, 6);
  bu.add_edge(2, 3);
  bu.add_edge(2, 4);
  bu.add_edge(2, 5);
  bu.add_edge(6, 7);
  bu.add_edge(6, 8);
  bu.add_edge(8, 9);
  bu.add_edge(5, 1);
  bu.add_edge(8, 1);
  bu.add_edge(9, 0);

  bu.build();

  DLOGK(bu.llk._ord);
  DLOGK(bu.llk._low);
  DLOGK(bu._tecc);
  DLOGK(bu.tecc_edges());
}


bool connected(ll n, const vpll& edges, ll nodes) { // nodes \subseteq [0..n)
  ll s = __builtin_popcountll(nodes);
  assert(s >= 0);
  UnionFind uf(n);
  for (auto [i, j] : edges) {
    if ((nodes >> i & 1) and (nodes >> j & 1)) uf.merge(i, j);
  }
  return uf.group_size(__builtin_ctzll(nodes)) == s;
}

int num_cc(ll n, const vpll& edges, ll nodes) {
  ll s = __builtin_popcountll(nodes);
  assert(s >= 0);
  UnionFind uf(n);
  for (auto [i, j] : edges) {
    if ((nodes >> i & 1) and (nodes >> j & 1)) uf.merge(i, j);
  }
  ll ret = 0;
  REP(i, 0, n) if ((nodes >> i & 1) and uf.leader(i) == i) ret++;
  return ret;
}

bool teconn(ll n, const vpll& edges, ll nodes) {
  if (not connected(n, edges, nodes)) {
    DLOGKL("false1", n, edges, nodes);
    return false;
  }
  REP(e, 0, SIZE(edges)) {
    vpll ee;
    REP(i, 0, SIZE(edges)) if (i != e) ee.push_back(edges[i]);
    if (not connected(n, ee, nodes)) {
      DLOGKL("false2", n, edges, e, ee, nodes);
      return false;
    }
  }
  DLOGKL("true1", n, edges, edges);
  return true;
}

bool bconn(ll n, const vpll& edges, ll nodes) {
  if (not connected(n, edges, nodes)) {
    return false;
  }
  ll s = __builtin_popcountll(nodes);
  assert(s >= 0);
  if (s == 1) {
    return true;
  }
  REP(i, 0, n) {
    if (not (nodes >> i & 1)) continue;
    vpll edges1;
    for (auto [j, k] : edges) if (j != i and k != i) edges1.emplace_back(j, k);
    if (not connected(n, edges1, nodes ^ (1LL << i))) {
      return false;
    }
  }
  return true;
}

void sane_bridge(ll n, const vpll& edges) {
  bridge bu(n);
  for (auto [i, j] : edges) bu.add_edge(i, j);

  ll orig_ncc = num_cc(n, edges, (1LL << n) - 1);
  ll num_bridges = 0;
  vector<bool> bridges(edges.size(), false);
  REP(i, 0, SIZE(edges)) {
    vpll edges1;
    REP(j, 0, SIZE(edges)) if (j != i) edges1.push_back(edges[j]);
    ll ncc = num_cc(n, edges1, (1LL << n) - 1);
    if (ncc > orig_ncc) {
      bridges[i] = true;
      num_bridges++;
    }
  }

  REP(e, 0, SIZE(edges)) {
    auto [i, j] = edges[e];
    assert(bu.is_bridge(i, j) == bridges[e]);
  }

  vector<ll> naive_tecc(1LL << n, -1);
  naive_tecc[0] = 0;
  ll num_naive_tecc = 0;
  REPrev(x, (1LL << n) - 1, 1) {
    if (naive_tecc[x] == 0) continue;
    if (teconn(n, edges, x)) {
      naive_tecc[x] = 1;
      num_naive_tecc++;
      for (ll y = (x - 1) & x; y > 0; y = (y - 1) & x) naive_tecc[y] = 0;
    }else naive_tecc[x] = 0;
  }
  if (bu.num_tecc() != num_naive_tecc) {
    DLOGK(bu.num_tecc(), num_naive_tecc);
    DLOGK(bu._tecc);
    DLOGK(naive_tecc);
    assert(bu.num_tecc() == num_naive_tecc);
  }
  REP(i, 0, bu.num_tecc()) {
    ll x = 0;
    for (ll j : bu.tecc(i)) x |= 1LL << j;
    assert(naive_tecc[x]);
  }
  
  vector<ll> belong(n);
  REP(i, 0, bu.num_tecc()) for (ll j : bu.tecc(i)) belong[j] = i;
  REP(i, 0, n) assert(bu.node_tecc_idx(i) == belong[i]);

  vector tbl1(n, vector(n, false));
  vector tbl2(n, vector(n, false));
  for (auto [i, j] : bu.tecc_edges()) {
    assert(tbl1[i][j] == false and tbl1[j][i] == false);
    tbl1[i][j] = tbl1[j][i] = true;
  }
  for (auto [u, v] : edges) {
    if (bu.is_bridge(u, v)) {
      ll i = belong[u], j = belong[v];
      assert(tbl2[i][j] == false and tbl2[j][i] == false);
      tbl2[i][j] = tbl2[j][i] = true;
    }
  }
  REP(i, 0, n) REP(j, 0, n) assert(tbl1[i][j] == tbl2[i][j]);

}

void sane_articulation(ll n, const vpll& edges) {
  articulation au(n);
  for (auto [i, j] : edges) au.add_edge(i, j);

  ll orig_ncc = num_cc(n, edges, (1LL << n) - 1);
  ll num_arts = 0;
  vector<bool> arts(n, false);
  REP(i, 0, n) {
    vpll edges1;
    for (auto [j, k] : edges) if (i != j and i != k) edges1.emplace_back(j, k);
    ll ncc = num_cc(n, edges1, ((1LL << n) - 1) ^ (1LL << i));
    if (ncc > orig_ncc) {
      num_arts++;
      arts[i] = true;
    }
  }

  REP(i, 0, n) assert(au.is_articulation(i) == arts[i]);

  vector<int> bcc(1LL << n, -1);
  bcc[0] = 0;
  ll num_bcc = 0;
  REPrev(x, (1LL << n) - 1, 1) {
    if (bcc[x] == 0) continue;
    if (bconn(n, edges, x)) {
      bcc[x] = 1;
      num_bcc++;
      for (ll y = (x - 1) & x; y > 0; y = (y - 1) & x) bcc[y] = 0;
    }else bcc[x] = 0;
  }
  
  assert(au.bcc_size() == num_bcc);
  REP(i, 0, au.bcc_size()) {
    ll x = 0;
    for (ll j : au.bcc(i)) x |= 1LL << j;
    assert(bcc[x]);
  }

  auto bct = au.make_bctree();
  assert(bct->size() == num_bcc + num_arts);

  auto bct_edges = bct->edges();
  for (auto [a1, a2] : bct_edges) {
    auto [w1, i1] = bct->what(a1);
    auto [w2, i2] = bct->what(a2);
    if (w1 == articulation::BLOCK) {
      swap(w1, w2);
      swap(i1, i2);
    }
    assert(w1 == articulation::CUT);
    assert(w2 == articulation::BLOCK);
    assert(0 <= i1 and i1 < n and arts[i1]);
    bool bb = false;
    for (int k : au._bcc[i2]) bb = bb or (k == i1);
    assert(bb);
  }

  auto edge_tbl = vector(bct->size(), vector(bct->size(), false));
  for (auto [a1, a2] : bct_edges) edge_tbl[a1][a2] = edge_tbl[a2][a1] = true;
  REP(i, 0, au.bcc_size()) {
    for (ll j : au.bcc(i)) {
      bool b1 = au.is_articulation(j);
      bool b2 = edge_tbl[bct->node(articulation::CUT, j)][bct->node(articulation::BLOCK, i)];
      assert(b1 == b2);
    }
  }
}

void test_random() {
  // ll rep_num = 100000;
  ll rep_num = 5000;

  REP(_r, 0, rep_num) {
    // ll n = randrange(2, 9);
    ll n = randrange(2, 7);
    ll ne = randrange(0, n * n);
    vpll edges;
    REP(i, 0, ne) edges.emplace_back(randrange(0, n), randrange(0, n));
    DLOGKL("*** start", n, edges);
    sane_bridge(n, edges);
    sane_articulation(n, edges);
  }
  
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  // test1();
  // test2();
  test_random();

}
