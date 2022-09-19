#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(tree)


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<TreeEdge> edge1({{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}});
  Tree t1(7);
  for (auto [x,y] : edge1) t1.add_edge(x, y);
  assert(t1.nnpath(1, 2) == vector<int>({1,0,2}));
  assert(t1.nnpath(3, 2) == vector<int>({3,1,0,2}));
  assert(t1.nnpath(6, 0) == vector<int>({6,2,0}));
  assert(t1.nnpath(4, 2) == vector<int>({4,1,0,2}));
  assert(t1.nnpath(2, 4) == vector<int>({2,0,1,4}));

  Tree t2(3);
  t2.add_edge(0, 1);
  t2.add_edge(0, 2);
  assert(t2.edgeIdx(0,1) == 0);
  assert(t2.edgeIdx(2,0) == 1);

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
    auto v = t.child(i);
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
    return make_pair(p.first + len5[t5.edgeIdx(n,c)], 0);
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
  assert(t6.numNodes = 8);
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
      ll eid = t7.edgeIdx(c, n);
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


  cerr << "test done." << endl;
  return 0;
}

