#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"
using pll = pair<ll, ll>;

// @@ !! LIM(offDynConn random UnionFind debug)

int main() {
  {
    OffDynConn odc(4, 4);
    odc.set_edge(1, 0, 1, true);
    odc.set_edge(1, 1, 2, true);
    odc.set_edge(2, 1, 2, false);
    odc.set_edge(2, 2, 3, true);
    auto f = [&](ll t) -> void {
      if (t == 0) {
        assert(odc.uuf.leader(0) != odc.uuf.leader(1));
        assert(odc.uuf.leader(0) != odc.uuf.leader(2));
      }
      if (t == 1) {
        assert(odc.uuf.leader(0) == odc.uuf.leader(1));
        assert(odc.uuf.leader(0) == odc.uuf.leader(2));
      }
      if (t == 2) {
        assert(odc.uuf.leader(1) != odc.uuf.leader(2));
        assert(odc.uuf.leader(2) == odc.uuf.leader(3));
      }
      if (t == 3) {
        assert(odc.uuf.leader(1) != odc.uuf.leader(2));
        assert(odc.uuf.leader(2) == odc.uuf.leader(3));
      }
    };
    odc.run(f);

  }

  {
    ll sz = 30;

    auto query = [&]() -> vector<tuple<ll, ll, ll>> {
      Random rand;
      vector conn(sz, vector(sz, false));

      auto gettwo = [&](ll mode) -> pll {
        while (true) {
          ll x = rand.range(0, sz);
          ll y = rand.range(0, sz);
          if (x == y) continue;
          if (mode < 0) return pll(x, y);
          if (mode == 0 and not conn[x][y]) return pll(x, y);
          if (mode == 1 and conn[x][y]) return pll(x, y);
        }
      };

      ll Q = rand.range(10, 520);
      vector<tuple<ll, ll, ll>> ret;
      ll nc = 0;
      double ratio12 = 0.03;
      double ratio3 = 0.2;
      double pool = 10000;
      REP(i, 0, Q) {
        if (rand.range(0, pool) < pool * ratio3) {
          auto [x, y] = gettwo(-1);
          ret.emplace_back(3, x, y);
        }else {
          ll mode = -1;
          if ((double)nc / (sz * sz) < ratio12 * 0.9) mode = 1;
          else if ((double)nc / (sz * sz) > ratio12 * 1.1) mode = 2;
          else if (rand.range(0, pool) < pool * ratio12) mode = 1;
          else mode = 2;
          if (mode == 1) {
            auto [x, y] = gettwo(0);
            ret.emplace_back(1, x, y);
            conn[x][y] = conn[y][x] = true;
            nc++;
          }else {
            auto [x, y] = gettwo(1);
            ret.emplace_back(2, x, y);
            conn[x][y] = conn[y][x] = false;
            nc--;
          }
        }
      }
      return ret;
    };

    auto naive = [&](const auto& qs) -> vector<bool> {
      vector<bool> ret;
      vector conn(sz, vector(sz, false));
      ll Q = SIZE(qs);
      REP(q, 0, Q) {
        auto [tp, x, y] = qs[q];
        if (tp == 1) conn[x][y] = conn[y][x] = true;
        else if (tp == 2) conn[x][y] = conn[y][x] = false;
        else if (tp == 3) {
          UnionFind uf(sz);
          REP(i, 0, sz) REP(j, i + 1, sz) if (conn[i][j]) uf.merge(i, j);
          ret.push_back(uf.leader(x) == uf.leader(y));
        }
      }
      return ret;
    };

    auto body = [&](const auto& qs) -> vector<bool> {
      vector<bool> ret;
      ll Q = SIZE(qs);
      ll tlim = 0;
      REP(q, 0, Q) {
        auto [tp, x, y] = qs[q];
        if (tp == 3) tlim++;
      }
      OffDynConn odc(sz, tlim);
      vector param(tlim, pll());
      auto f = [&](ll t) -> void {
        auto [x, y] = param[t];
        ret.push_back(odc.uuf.leader(x) == odc.uuf.leader(y));
      };
      ll t = 0;
      REP(q, 0, Q) {
        auto [tp, x, y] = qs[q];
        if (tp == 1) odc.set_edge(t, x, y, true);
        else if (tp == 2) odc.set_edge(t, x, y, false);
        else if (tp == 3) {
          param[t] = pll(x, y);
          t++;
          if (t == tlim) break;
        }
        else assert(0);
      }
      odc.run(f);
      return ret;
    };

    REP(rep, 0, 1000) {
      auto qs = query();
      auto n_res = naive(qs);
      auto b_res = body(qs);
      // DLOGK(n_res);
      // DLOGK(b_res);
      assert(SIZE(n_res) == SIZE(b_res));
      REP(i, 0, SIZE(n_res)) { assert(n_res[i] == b_res[i]); }
    }
  }


  cerr << "ok\n";
  
  return 0;
}


