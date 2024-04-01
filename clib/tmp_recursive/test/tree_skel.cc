#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define SIZE(v) ((ll)((v).size()))
using u64 = unsigned long long;

// @@ !! LIM(mod debug tree)


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  using TreeEdge = pair<int, int>;

  {
    vector<TreeEdge> edge1({{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}});
    Tree t1(7);
    for (auto [x,y] : edge1) t1.add_edge(x, y);
    assert(t1.nnpath(1, 2) == vector<int>({1,0,2}));
    assert(t1.nnpath(3, 2) == vector<int>({3,1,0,2}));
    assert(t1.nnpath(6, 0) == vector<int>({6,2,0}));
    assert(t1.nnpath(4, 2) == vector<int>({4,1,0,2}));
    assert(t1.nnpath(2, 4) == vector<int>({2,0,1,4}));
    assert(t1.parent(0) == -1);
    assert(t1.parent(1) == 0);
    assert(t1.parent(6) == 2);
    vector<int> v;
    for (int c : t1.children(0)) v.push_back(c);
    sort(v.begin(), v.end());
    assert(v == vector<int>({1, 2}));
    assert(t1.stsize(0) == 7);
    assert(t1.stsize(2) == 3);
    assert(t1.stsize(5) == 1);
    assert(t1.depth(0) == 0);
    assert(t1.depth(1) == 1);
    assert(t1.depth(4) == 2);
  }

  {
    using pii = pair<int, int>;
    Tree t2(3);
    t2.add_edge(0, 1);
    t2.add_edge(0, 2);
    assert(t2.edge_idx(0,1) == 0);
    assert(t2.edge_idx(2,0) == 1);
    assert(t2.nodes_of_edge(0) == pii(0, 1));
    assert(t2.nodes_of_edge(1) == pii(0, 2));
  }

  vector<TreeEdge>
    edge3({{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7},
	   {6,8}, {3,9}, {9,10}, {0,11}, {11,12}, {11,13}});
  Tree t3(14);
  for (auto [x,y] : edge3) t3.add_edge(x, y);
  assert(t3.nnpath(1,5) == vector<int>({1,2,3,4,5}));
  assert(t3.nnpath(7,2) == vector<int>({7,6,5,4,3,2}));
  for (int i = 0; i <=7; i++) assert(t3.ancestorDep(7,i) == i);
  assert(t3.lca(7,8) == 6);
  assert(t3.lca(8,13) == 0);
  assert(t3.lca(7,10) == 3);

  vector<TreeEdge>
    edge4({{0,1}, {1,2}, {3,4}, {0,3}, {3,5}, {6,7}, {6,8}, {6,1}});
  Tree t4(9);
  for (auto [x,y] : edge4) t4.add_edge(x, y);
  auto sub4 = [](Tree t, int i)  {
    vector<int> v;
    for (int j = 0; j < t.num_children(i); j++) v.push_back(t.child(i, j));
    return set<int>(v.begin(), v.end());
  };
  assert(sub4(t4, 0) == set<int>({1,3}));
  assert(sub4(t4, 1) == set<int>({2,6}));
  assert(sub4(t4, 3) == set<int>({4,5}));
  assert(sub4(t4, 6) == set<int>({7,8}));
  assert(sub4(t4, 8) == set<int>());
  assert(t4.parent(0) == -1);
  assert(t4.parent(1) == 0);
  assert(t4.parent(2) == 1);
  assert(t4.parent(6) == 1);
  assert(t4.parent(8) == 6);

  {
    Tree tr(6);
    tr.add_edge(0, 1);
    tr.add_edge(0, 2);
    tr.add_edge(0, 4);
    tr.add_edge(1, 3);
    tr.add_edge(4, 5);
    auto [diam, ep0, ep1, ct0, ct1] = tr.diameter();
    assert(diam == 4 and ep0 == 3 and ep1 == 5 and ct0 == 0 and ct1 == 0);
    tr.change_root(3);
    tie (diam, ep0, ep1, ct0, ct1) = tr.diameter();
    assert(diam == 4 and ep0 == 5 and ep1 == 3 and ct0 == 0 and ct1 == 0);
    Tree tr2(7);
    tr2.add_edge(0, 1);
    tr2.add_edge(0, 2);
    tr2.add_edge(0, 4);
    tr2.add_edge(1, 3);
    tr2.add_edge(4, 5);
    tr2.add_edge(5, 6);
    tie (diam, ep0, ep1, ct0, ct1) = tr2.diameter();
    assert(diam == 5 and ep0 == 6 and ep1 == 3 and ct0 == 4 and ct1 == 0);
    tr2.change_root(4);
    tie (diam, ep0, ep1, ct0, ct1) = tr2.diameter();
    assert(diam == 5 and ep0 == 3 and ep1 == 6 and ct0 == 0 and ct1 == 4);
  }

  {
    ll repeat = 2000;
    for (ll rep = 0; rep < repeat; rep++) {
      ll N = randrange(1, 17);
      ll root = randrange(0, N);
      Tree tr(N, root);
      vector conn(N, vector<bool>(N, false));
      vector rec(N, 0LL);
      for (ll i = 1; i < N; i++) {
        ll j = randrange(0, i);
        rec[i] = j;
        conn[i][j] = conn[j][i] = true;
        if (randrange(0, 100) < 50) tr.add_edge(i, j);
        else                        tr.add_edge(j, i);
      }
      for (ll i = 0; i < N - 1; i++) {
        auto [x, y] = tr.nodes_of_edge(i);
        assert ((x == i + 1 and y == rec[i + 1]) or (x == rec[i + 1] and y == i + 1));
      }
      for (ll i = 0; i < N; i++) {
        ll cnt = 0;
        for (ll j = 0; j < N; j++) if (conn[i][j]) cnt++;
        for (ll k = 0; k < tr.num_children(i); k++) assert(conn[i][tr.child(i, k)]);
        ll sts = 1; for (ll j : tr.children(i)) sts += tr.stsize(j);
        assert(sts == tr.stsize(i));
        if (i == root) {
          assert (tr.parent(i) == -1);
          assert ((ll)(tr.num_children(i)) == cnt);
          assert (tr.depth(i) == 0);
          assert (tr.stsize(i) == N);
          assert (tr.ancestorDep(i, 0) == i);
        }else {
          assert (conn[i][tr.parent(i)]);
          assert (tr.num_children(i) + 1 == cnt);
          assert (tr.depth(i) == tr.depth(tr.parent(i)) + 1);
          vector tmp(tr.depth(i) + 1, 0LL);
          for (ll d = 0; d <= tr.depth(i); d++) tmp[d] = tr.ancestorDep(i, d);
          for (ll d = 1; d <= tr.depth(i); d++) assert (tr.parent(tmp[d]) == tmp[d - 1]);
        }
      }
      {
        for (int nd = 0; nd < N; nd++) {
          int nc = 0;
          for (int cld : tr.children(nd)) {
            assert(nd == tr.parent(cld));
            assert(cld == tr.child(nd, nc));
            auto [p, e] = tr.parent_pe(cld);
            assert(nd == p and tr.nodes_of_edge(e) == make_pair(min(nd, cld), max(nd, cld)));
            assert(tr.child_pe(nd, nc).peer == cld and tr.child_pe(nd, nc).edge == e);
            nc++;
          }
          assert(nc == tr.num_children(nd));
          int i = 0;
          for (auto [cld, e1] : tr.children_pe(nd)) {
            auto [p, e2] = tr.parent_pe(cld);
            assert(p == nd and e1 == e2);
            int e3 = tr.child_edge(nd, i);
            assert(e1 == e3);
            assert(e1 == tr.edge_idx(nd, cld));
            i++;
          }
        }
      }
      for (ll x = 0; x < N; x++) {
        for (ll y = 0; y < N; y++) {
          ll z = tr.lca(x, y);
          ll dz = tr.depth(z);
          ll dx = tr.depth(x);
          ll dy = tr.depth(y);
          assert (dx >= dz and tr.ancestorDep(x, dz) == z);
          assert (dy >= dz and tr.ancestorDep(y, dz) == z);
          if (dx > dz and dy > dz) assert(tr.ancestorDep(x, dz + 1) != tr.ancestorDep(y, dz + 1));
          const auto vec = tr.nnpath(x, y);
          for (ll i = 0; i < SIZE(vec); i++) for (ll j = i + 1; j < SIZE(vec); j++) assert(vec[i] != vec[j]);
          assert (vec[0] == x and vec.back() == y);
          for (ll i = 0; i < SIZE(vec) - 1; i++) assert(conn[vec[i]][vec[i + 1]]);
          if (conn[x][y]) assert (tr.edge_idx(x, y) == max(x, y) - 1);
          else            assert (tr.edge_idx(x, y) == -1);
        }
      }
      { // getting LCA using euler tour and sparse table
        int sz = 2 * N - 1;
        int K = countr_zero(bit_floor((u64)sz));
        vector sp_tbl(K + 1, vector(sz, -1));
        for (int i = 0; i < sz; i++) {
          auto [e, x, y] = tr.euler_edge(i);
          sp_tbl[0][i] = y;
        }
        for (int k = 1; k <= K; k++) {
          for (int i = 0; i < sz; i++) {
            if (i + (1 << k) > sz) break;
            int x = sp_tbl[k - 1][i];
            int y = sp_tbl[k - 1][i + (1 << (k - 1))];
            sp_tbl[k][i] = tr.depth(x) <= tr.depth(y) ? x : y;
          }
        }
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int x = tr.lca(i, j);
            int y = -1, t0 = i, t1 = j;
            int i0 = tr.euler_in(i), o0 = tr.euler_out(i), i1 = tr.euler_in(j), o1 = tr.euler_out(j);
            assert(i0 != i1 and o0 != o1);
            if (i0 > i1) { swap(t0, t1); swap(i0, i1); swap(o0, o1); }
            if (o1 < o0) y = t0;
            else {
              assert(o0 < i1);
              int len = i1 - o0;
              int k = countr_zero(bit_floor((u64)len));
              int u = sp_tbl[k][o0];
              int v = sp_tbl[k][i1 - (1 << k)];
              y = tr.depth(u) <= tr.depth(v) ? u : v;
            }
            assert(x == y);
          }
      }
      {
        auto [diam, nd0, nd1, ct0, ct1] = tr.diameter();
        ll ndiam = 0;
        for (ll x = 0; x < N; x++) for (ll y = x + 1; y < N; y++) ndiam = max(ndiam, SIZE(tr.nnpath(x, y)) - 1);
        assert (diam == ndiam);
        auto path = tr.nnpath(nd0, nd1);
        assert (SIZE(path) - 1 == diam);
        if (diam % 2 == 0) assert (ct0 == ct1 and ct0 == path[diam / 2]);
        else assert(ct0 == path[diam / 2] and ct1 == path[diam / 2 + 1]);
      }
      ll newRoot = randrange(0, N);
      tr.change_root(newRoot);
      for (ll i = 0; i < N; i++) {
        ll cnt = 0;
        for (ll j = 0; j < N; j++) if (conn[i][j]) cnt++;
        for (ll j : tr.children(i)) assert(conn[i][j]);
        if (i == newRoot) {
          assert (tr.parent(i) == -1);
          assert ((ll)(tr.num_children(i)) == cnt);
          assert (tr.depth(i) == 0);
          assert (tr.stsize(i) == N);
        }else {
          assert (conn[i][tr.parent(i)]);
          assert (tr.num_children(i) + 1 == cnt);
          assert (tr.depth(i) == tr.depth(tr.parent(i)) + 1);
        }
      }
    }
  }

  // Euler Tour
  {
    int rep = 1000;
    for (int _r = 0; _r < rep; _r++) {
      int nn = randrange(1, 17);
      int root = randrange(0, nn);
      Tree tr(nn, root);
      for (int i = 1; i < nn; i++) {
        int j = randrange(0, i);
        if (randrange(0, 2) == 0) tr.add_edge(i, j);
        else                      tr.add_edge(j, i);
      }

      auto dfs = [&](auto rF, int nd) -> vector<int> {
        int ein = tr.euler_in(nd);
        int eout = tr.euler_out(nd);
        vector<int> v{ein, eout};
        if (tr.num_children(nd) == 0) {
          assert(ein + 1 == eout);
          return v;
        }else {
          for (int i : tr.children(nd)) {
            auto w = rF(rF, i);
            v.insert(v.end(), w.begin(), w.end());
          }
          sort(v.begin(), v.end());
          assert(v[0] == ein);
          assert(v.back() == eout);
          assert(ssize(v) == eout - ein + 1);
          for (int i = 0; i < ssize(v) - 1; i++) v[i + 1] = v[i] + 1;
        }
        return v;
      };
      dfs(dfs, root);
    }
  }


  // The length of the longest simple path that goes through the node
  using T5 = pair<ll, ll>;
  vector<TreeEdge> edge5({{0,1}, {0,2}, {0,3}, {1,4}, {1,5}, {2,6}, {2,7}});
  vector<ll> len5({10,6,3,5,3,2,1});
  Tree t5(8);
  for (auto [x,y] : edge5) t5.add_edge(x, y);
  auto add5 = [&](T5 p1, T5 p2) -> T5 {
    ll a1 = p1.first;
    ll a2 = p2.first;
    if (a1 < a2) swap(a1, a2);
    if (a2 < p1.second) a2 = p1.second;
    if (a2 < p2.second) a2 = p2.second;
    return make_pair(a1, a2);
  };
  auto mod5 = [&](T5 p, ll n, ll c) -> T5 {
    return make_pair(p.first + len5[t5.edge_idx(n,c)], 0);
  };
  auto v5 = reroot(t5, make_pair(0, 0), add5, mod5);
  vector<ll> ans5 = {23, 23, 23, 18, 23, 21, 23, 22};
  assert(t5.numNodes == 8);
  for (ll i = 0; i < t5.numNodes; i++) {
    assert(v5[i].first + v5[i].second == ans5[i]);
  }

  // ABC160-F
  using T6 = pair<ll, ll>;
  const T6 unitT6({0, 1});
  auto fact6 = [&](const auto& recF, ll n) -> ll {
    if (n == 0) return 1;
    return n * recF(recF, n-1);
  };
  auto add6 = [&](T6 tt1, T6 tt2) -> T6 {
    ll card1; ll perm1; tie(card1, perm1) = tt1;
    ll card2; ll perm2; tie(card2, perm2) = tt2;
    ll card = card1 + card2;
    ll perm = perm1 * perm2 * fact6(fact6, card)
                  / (fact6(fact6, card1) * fact6(fact6, card2));
    T6 ret = make_pair(card, perm);
    return ret;
  };
  auto mod6 = [&](T6 t, ll n, ll c) -> T6 {
    return make_pair(t.first + 1, t.second);
  };
  vector<TreeEdge> edge6({{0,1}, {1,2}, {2,3}, {2,4}, {2,5}, {5,6}, {5,7}});
                                // input No.4
  Tree t6(8);
  for (auto [x, y] : edge6) t6.add_edge(y, x);
  auto res6 = reroot(t6, unitT6, add6, mod6);
  vector<ll> ans6({40,280,840,120,120,504,72,72}); 
  assert(t6.numNodes == 8);
  for (ll i = 0; i < 8; i++) assert(res6[i].second == ans6[i]);

  // NJPC2017-E   https://njpc2017.contest.atcoder.jp/tasks/njpc2017_e
  vector<TreeEdge> edge7({{1,0},{2,1},{1,3},{3,4},{3,5},{6,5}});
  vector<ll> time({2,3,5,1,4,6});
  for (ll rt = 0; rt < 7; rt++) {
    Tree t7(7, rt);
    for (auto [x,y] : edge7) t7.add_edge(x, y);
    using T7 = pair<ll, ll>;
    const T7 unitT7 = make_pair(0, 0);
    auto  add7 = [&](const T7& tt1, const T7& tt2) -> T7 {
      ll top1, rev1; tie(top1, rev1) = tt1;
      ll top2, rev2; tie(top2, rev2) = tt2;
      return make_pair(max(top1, top2), rev1 + rev2);
    };
    auto mod7 = [&](const T7& t, ll n, ll c) -> T7 {
      ll eid = t7.edge_idx(c, n);
      ll addRev = (edge7[eid].first == n) ? 1 : 0;
      return make_pair(t.first + time[eid], t.second + addRev);
    };
    auto res7 = reroot(t7, unitT7, add7, mod7);
    { ll x, z;
      tie(x, z) = res7[1]; assert(x == 15 && z == 4);
      tie(x, z) = res7[3]; assert(x == 10 && z == 3);
      tie(x, z) = res7[4]; assert(x == 11 && z == 2);
      tie(x, z) = res7[5]; assert(x == 12 && z == 2);
    }
  }

  { // ABC 160F rewritten

    using Fp = FpA;

    ll N = 8;
    Tree tr(N);
    tr.add_edge(0, 1);
    tr.add_edge(1, 2);
    tr.add_edge(2, 3);
    tr.add_edge(2, 4);
    tr.add_edge(2, 5);
    tr.add_edge(5, 6);
    tr.add_edge(5, 7);

    Comb<Fp> cb(N);

    using sta = pair<Fp, ll>;
    sta unit = sta{Fp(1), 0LL};
    auto myadd = [&](const sta& p1, const sta& p2) -> sta {
      return sta(p1.first * p2.first , p1.second + p2.second);
    };
    auto mod1 = [&](sta p, int nd, int cd) -> sta { return sta(p.first / cb.fact(p.second), p.second); };
    auto mod2 = [&](sta p, int nd) -> sta { return sta(p.first * cb.fact(p.second), p.second + 1); };
    auto result = reroot(tr, unit, myadd, mod1, mod2);
    vector<ll> expected{40, 280, 840, 120, 120, 504, 72, 72};
    for (ll i = 0; i < N; i++) assert(result[i].first == expected[i]);
  }


  cerr << "test done." << endl;
  return 0;
}

