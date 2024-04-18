#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(UnionFind FuncGraph)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  {
    FuncGraph fg(4);
    fg.add_edge(0, 1);
    fg.add_edge(1, 3);
    fg.add_edge(2, 2);
    fg.add_edge(3, 1);
    assert(fg.numcc() == 2);
    assert(fg.ccid(0) == fg.ccid(1) and fg.ccid(1) == fg.ccid(3));
    assert(fg.ccid(0) != fg.ccid(2));
    assert(fg.cc_size(0) == 3);
    assert(fg.cc_size(1) == 3);
    assert(fg.cc_size(2) == 1);
    assert(fg.cc_size(3) == 3);
    assert(fg.cycle_size(0) == 2);
    assert(fg.cycle_size(1) == 2);
    assert(fg.cycle_size(2) == 1);
    assert(fg.cycle_size(3) == 2);
    assert(fg.node_on_cycle(0) == 1);
    assert(fg.node_on_cycle(1) == 1);
    assert(fg.node_on_cycle(2) == 2);
    assert(fg.node_on_cycle(3) == 3);
    assert(not fg.is_on_cycle(0));
    assert(fg.is_on_cycle(1));
    assert(fg.is_on_cycle(2));
    assert(fg.is_on_cycle(3));
    assert(fg.dist_to_cycle(0) == 1);
    assert(fg.dist_to_cycle(1) == 0);
    assert(fg.dist_to_cycle(2) == 0);
    assert(fg.dist_to_cycle(3) == 0);
  }
  
  {
    FuncGraph fg(3);
    fg.add_edge(0, 1);
    fg.add_edge(1, 0);
    fg.add_edge(2, 1);
    assert(fg.numcc() == 1);
    assert(fg.cc_size(0) == 3);
    assert(fg.cc_size(1) == 3);
    assert(fg.cc_size(2) == 3);
    assert(fg.cycle_size(0) == 2);
    assert(fg.cycle_size(1) == 2);
    assert(fg.cycle_size(2) == 2);
    assert(fg.node_on_cycle(0) == 0);
    assert(fg.node_on_cycle(1) == 1);
    assert(fg.node_on_cycle(2) == 1);
    assert(fg.is_on_cycle(0));
    assert(fg.is_on_cycle(1));
    assert(not fg.is_on_cycle(2));
    assert(fg.dist_to_cycle(0) == 0);
    assert(fg.dist_to_cycle(1) == 0);
    assert(fg.dist_to_cycle(2) == 1);
  }
  

  {
    int numRep = 10000;
    int sizeLim = 16;
    for (int rep = 0; rep < numRep; rep++) {
      int size = randrange(1, sizeLim);
      FuncGraph fg(size);
      UnionFind uf(size);
      for (int i = 0; i < size; i++) {
        int j = randrange(0, size);
        fg.add_edge(i, j);
        uf.merge(i, j);
      }
      ll nuf = 0; for (int i = 0; i < size; i++) if (uf.leader(i) == i) nuf++;
      assert(nuf == fg.numcc());
      for (int i = 0; i < size; i++) for (int j = i + 1; j < size; j++) {
          assert((uf.leader(i) == uf.leader(j)) == (fg.ccid(i) == fg.ccid(j)));
        }
      for (int i = 0; i < size; i++) assert(fg.cc_size(i) == uf.group_size(i));
      for (int i = 0; i < size; i++) {
        ll p = fg.dist_to_cycle(i);
        ll c = fg.cycle_size(i);
        vector<int> traj(p + c);
        for (int j = 0, m = i; j < p + c; j++, m = fg.fwd[m]) traj[j] = m;
        for (int j = 0; j < p + c; j++) for (int k = j + 1; k < p + c; k++) assert(traj[j] != traj[k]);
        assert(fg.fwd[traj.back()] == traj[p]);
        assert(fg.node_on_cycle(i) == traj[p]);
        assert(fg.is_on_cycle(i) == (p == 0));
      }
    }
  }

  cout << "ok" << endl;
  return 0;
}

