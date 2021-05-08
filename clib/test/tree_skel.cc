#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:updMaxMin tree)


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<Edge> edge1({{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}});
  Tree t1(edge1);
  assert(t1.nnpath(1, 2) == vector<int>({1,0,2}));
  assert(t1.nnpath(3, 2) == vector<int>({3,1,0,2}));
  assert(t1.nnpath(6, 0) == vector<int>({6,2,0}));
  assert(t1.nnpath(4, 2) == vector<int>({4,1,0,2}));
  assert(t1.nnpath(2, 4) == vector<int>({2,0,1,4}));

  stringstream ss2("3\n1 2\n1 3\n");
  ll N; ss2 >> N;
  vector<Edge> ve;
  for (ll i = 0; i < N - 1; i++) ve.push_back(Edge(ss2, 1));
  Tree t2(move(ve));
  assert(t2.edge.at(1) == make_pair(0, 2));
  assert(t2.node2edgeID(0,1) == 0);
  assert(t2.node2edgeID(2,0) == 1);

  vector<Edge>
    edge3({{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7},
	   {6,8}, {3,9}, {9,10}, {0,11}, {11,12}, {11,13}});
  Tree t3(edge3);
  assert(t3.nnpath(1,5) == vector<int>({1,2,3,4,5}));
  assert(t3.nnpath(7,2) == vector<int>({7,6,5,4,3,2}));
  for (int i = 0; i <=7; i++) assert(t3.ancestorDep(7,i) == i);
  assert(t3.lca(7,8) == 6);
  assert(t3.lca(8,13) == 0);
  assert(t3.lca(7,10) == 3);
  assert(t3.diameter() == 9);

  vector<Edge>
    edge4({{0,1}, {1,2}, {3,4}, {0,3}, {3,5}, {6,7}, {6,8}, {6,1}});
  Tree t4(edge4);
  auto sub4 = [](Tree t, int i)  {
    auto v = t.child.at(i);
    return set<int>(v.begin(), v.end());
  };
  assert(sub4(t4, 0) == set<int>({1,3}));
  assert(sub4(t4, 1) == set<int>({2,6}));
  assert(sub4(t4, 3) == set<int>({4,5}));
  assert(sub4(t4, 6) == set<int>({7,8}));
  assert(sub4(t4, 8) == set<int>());
  assert(t4.parent.at(0) == 0);
  assert(t4.parent.at(1) == 0);
  assert(t4.parent.at(2) == 1);
  assert(t4.parent.at(6) == 1);
  assert(t4.parent.at(8) == 6);

  // The length of the longest simple path that goes through the node
  using T5 = pair<ll, ll>;
  vector<Edge> edge5({{0,1}, {0,2}, {0,3}, {1,4}, {1,5}, {2,6}, {2,7}});
  vector<ll> len5({10,6,3,5,3,2,1});
  Tree t5(edge5);
  auto add5 = [&](T5 p1, T5 p2) -> T5 {
    ll a1 = p1.first;
    ll a2 = p2.first;
    if (a1 < a2) swap(a1, a2);
    if (a2 < p1.second) a2 = p1.second;
    if (a2 < p2.second) a2 = p2.second;
    return make_pair(a1, a2);
  };
  auto mod5 = [&](T5 p, ll n, ll c) -> T5 {
    return make_pair(p.first + len5.at(t5.node2edgeID(n,c)), 0);
  };
  auto v5 = reroot(t5, make_pair(0, 0), add5, mod5);
  vector<ll> ans5 = {23, 23, 23, 18, 23, 21, 23, 22};
  assert(t5.numNodes == 8);
  for (ll i = 0; i < t5.numNodes; i++) {
    assert(v5.at(i).first + v5.at(i).second == ans5.at(i));
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
  vector<Edge> edge6({{0,1}, {1,2}, {2,3}, {2,4}, {2,5}, {5,6}, {5,7}});
                                // input No.4
  Tree t6(edge6);
  auto res6 = reroot(t6, unitT6, add6, mod6);
  vector<ll> ans6({40,280,840,120,120,504,72,72}); 
  assert(t6.numNodes = 8);
  for (ll i = 0; i < 8; i++) assert(res6.at(i).second == ans6.at(i));

  // NJPC2017-E   https://njpc2017.contest.atcoder.jp/tasks/njpc2017_e
  vector<Edge> edge7({{1,0},{2,1},{1,3},{3,4},{3,5},{6,5}});
  vector<ll> time({2,3,5,1,4,6});
  for (ll rt = 0; rt < 7; rt++) {
    Tree t7(edge7, rt);
    using T7 = pair<ll, ll>;
    const T7 unitT7 = make_pair(0, 0);
    auto  add7 = [&](const T7& tt1, const T7& tt2) -> T7 {
      ll top1, rev1; tie(top1, rev1) = tt1;
      ll top2, rev2; tie(top2, rev2) = tt2;
      return make_pair(max(top1, top2), rev1 + rev2);
    };
    auto mod7 = [&](const T7& t, ll n, ll c) -> T7 {
      ll eid = t7.node2edgeID(c, n);
      ll addRev = (t7.edge.at(eid).first == n) ? 1 : 0;
      return make_pair(t.first + time.at(eid), t.second + addRev);
    };
    auto res7 = reroot(t7, unitT7, add7, mod7);
    { ll x, z;
      tie(x, z) = res7.at(1); assert(x == 15 && z == 4);
      tie(x, z) = res7.at(3); assert(x == 10 && z == 3);
      tie(x, z) = res7.at(4); assert(x == 11 && z == 2);
      tie(x, z) = res7.at(5); assert(x == 12 && z == 2);
    }
  }


  cerr << "test done." << endl;
  return 0;
}

