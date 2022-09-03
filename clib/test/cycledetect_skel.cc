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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(cycledetect)

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    vector<ll> ff{2,3,5,1,0,0};
    auto f = [&](ll i) -> ll { return ff[i]; };
    auto [vec4, idx4] = func_cycle_detect(6, 4, f);
    assert(vec4 == (vector<int>{4, 0, 2, 5}));
    assert(idx4 == 1);
    auto [vec1, idx1] = func_cycle_detect(6, 1, f);
    assert(vec1 == (vector<int>{1, 3}));
    assert(idx1 == 0);
  }
  {
    vector<vector<ll>> fwd{{1}, {5}, {3, 5}, {}, {2}, {0}};
    auto [vec4, idx4] = directed_cycle_detect(6, 4, fwd);
    assert(vec4 == (vector<int>{4, 2, 5, 0, 1}));
    assert(idx4 == 2);
    auto [vec3, idx3] = directed_cycle_detect(6, 3, fwd);
    assert(vec3.empty());
    assert(idx3 == -1);
  }
  {
    vector<vector<ll>> nbr{{1,4}, {0}, {3}, {2}, {0, 5}, {0, 4}};
    auto [vec1, idx1] = undirected_cycle_detect(6, 1, nbr);
    assert(vec1 == (vector<int>{1, 0, 4, 5}));
    assert(idx1 == 1);
    auto [vec2, idx2] = undirected_cycle_detect(6, 2, nbr);
    assert(vec2.empty());
    assert(idx2 == -1);
  }

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  {
    ll repeat = 20;
    REP(_r, 0, repeat) {
      ll n = 20;
      vector<ll> ff(n);
      REP(i, 0, n) ff[i] = randrange(0, n);
      auto f = [&](ll i) -> ll { return ff[i]; };
      REP(j, 0, 5) {
        auto [vec, idx] = func_cycle_detect(n, j, f);
        assert(vec[0] == j);
        REP(k, 0, SIZE(vec) - 1) assert(vec[k + 1] == f(vec[k]));
        assert(f(vec.back()) == vec[idx]);
      }
    }
  }
  {
    ll repeat = 20;
    REP(_r, 0, repeat) {
      ll n = 20;
      vector<set<ll>> fwd(n);
      ll prev = 0;
      ll target = randrange(0, 8);
      ll z;
      REP(i, 0, 8) {
        ll y = randrange(0, n);
        if (i == target) z = y;
        fwd[prev].insert(y);
        prev = y;
      }

      auto check = [&](auto& vec, ll j, ll idx) {
        assert(vec[0] == j);
        REP(k, 0, SIZE(vec) - 1) assert(fwd[vec[k]].find(vec[k + 1]) != fwd[vec[k]].end());
        assert(fwd[vec.back()].find(vec[idx]) != fwd[vec.back()].end());
      };

      fwd[prev].insert(z);
      auto [vec0, idx0] = directed_cycle_detect(n, 0, fwd);
      assert(not vec0.empty());
      assert(idx0 >= 0);
      check(vec0, 0, idx0);
    }
  }


  cerr << "ok" << endl;
  return 0;
}

