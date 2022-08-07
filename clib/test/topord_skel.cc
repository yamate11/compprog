#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(topord)

struct TopOrd_test {

  bool correct_order(const auto& vec, auto& fwd) {
    ll n = vec.size();
    vector trcl(n, vector(n, false));
    REP(i, n) trcl[i][i] = true;
    REP(i, n) for (ll j : fwd[i]) trcl[i][j] = true;
    REP(k, n) REP(i, n) REP(j, n) if (trcl[i][k] and trcl[k][j]) trcl[i][j] = true;
    REP(i, n) REP2(j, i + 1, n) if (trcl[vec[j]][vec[i]]) return false;
    return true;
  }

  bool to_correct(TopOrd& to) {
    ll n = to.size();
    auto& vec = to.sorted();
    if ((ll)vec.size() != n) return false;
    return correct_order(vec, to.fwd);
  }

  void run() {
    random_device rd;
    mt19937 rng(rd());
    auto randrange = [&rng](ll i, ll j) -> ll {
      uniform_int_distribution<ll> dist(i, j - 1);
      return dist(rng);
    };

    {
      // testing correct_order
      vector<vector<ll>> fwd{{1}, {2, 3}, {}, {}};
      vector<ll> vec1{0, 1, 2, 3};
      vector<ll> vec2{0, 1, 3, 2};
      vector<ll> vec3{0, 2, 1, 3};
      vector<ll> vec4{3, 0, 1, 2};
      assert(correct_order(vec1, fwd));
      assert(correct_order(vec2, fwd));
      assert(not correct_order(vec3, fwd));
      assert(not correct_order(vec4, fwd));
    }

    {
      TopOrd to(4);
      to.add_edge(0, 1);
      to.add_edge(0, 2);
      to.add_edge(2, 3);
      assert(to_correct(to));
    }

    {
      REP(_cnt, 1000) {
        ll n = 10;
        ll maxfail = 4;
        vector edge(n, vector(n, false));
        vector trcl(n, vector(n, false));
        REP(i, n) trcl[i][i] = true;
        ll m = randrange(0, n * (n - 1) / 2);
        REP(i, m) {
          REP(_f, maxfail) {
            ll x = randrange(0, n);
            ll y = randrange(0, n);
            if (not trcl[y][x]) {
              edge[x][y] = true;
              REP(j, n) REP(k, n) if (trcl[j][x] and trcl[y][k]) trcl[j][k] = true;
              break;
            }
          }
        }
        TopOrd to(n);
        REP(i, n) REP(j, n) if (edge[i][j]) to.add_edge(i, j);
        assert(to_correct(to));
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  TopOrd_test t;
  t.run();

}


