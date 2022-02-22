#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:<< debug mod matrix adjMatrix)

int main(/* int argc, char *argv[] */) {
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
    vector<pair<int, int>> a1({{1, 2}, {1, 0}});
    vector<pair<ll, ll>> a2({{1, 2}, {1, 0}});
    vector<ll> v1({4, 5, -9});
    auto w1 = adjMatEq(a1, v1).value();
    auto w2 = adjMatEq(a2, v1).value();
    assert(w1.size() == w2.size());
  }
  
  if (1) {
    using Fp = FpA;
    ll rep = 1000;
    ll has_sol = 0, no_sol = 0;
    for (ll _r = 0; _r < rep; _r++) {
      ll numV = randrange(10, 20);
      ll numE = randrange(numV / 2, numV * (numV - 1) / 4);
      auto chk = vector(numV, vector(numV, false));
      auto adj = vector<pair<ll, ll>>();
      for (ll i = 0; i < numE;) {
        ll x = randrange(0, numV);
        ll y = randrange(0, numV);
        if (x == y) continue;
        if (chk[x][y]) continue;
        chk[x][y] = true;
        chk[y][x] = true;
        adj.emplace_back(x, y);
        i++;
      }
      auto bs = vector(numV, Fp(0));
      for (ll i = 0; i < numV; i++) {
        ll x = randrange(0, numV);
        ll y = randrange(0, numV);
        Fp c = Fp(randrange(-6, 7));
        bs[x] += c;
        bs[y] -= c;
      }
      auto optsol1 = adjMatEq(adj, bs);
      Matrix<Fp> mat(numV, numE);
      for (ll i = 0; i < numE; i++) {
        auto [x, y] = adj[i];
        mat.at(x, i) = 1;
        mat.at(y, i) = -1;
      }
      auto optsol2 = mat.linSolution(Matrix<Fp>(0, 1, bs));
      if (optsol1.has_value()) {
        assert(optsol2.has_value());
        auto colv = Matrix<Fp>(0, 1, optsol1.value());
        auto lhs = mat * colv;
        assert(mat * colv == Matrix<Fp>(0, 1, bs));
        has_sol++;
      }else {
        assert(!optsol2.has_value());
        no_sol++;
      }
    }
    // DLOGK(has_sol, no_sol);
  }

  cout << "ok" << endl;
  return 0;
}

