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

// @@ !! LIM(random)

// ---- inserted library file random.cc


struct Random {
  static random_device the_random_device;
  mt19937_64 rng;

  Random() : rng(the_random_device()) {}
  Random(unsigned seed) : rng(seed) {}
  
  ll range(ll i, ll j) {
    if (i >= j) {
      throw runtime_error("Random.range: invalid range");
    }
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  }

  double rand(double a, double b) {
    if (!(a <= b)) {
      throw std::runtime_error("Random.rand: invalid range");
    }
    std::uniform_real_distribution<double> dist(a, b);
    return dist(rng);
  }

  pair<ll, ll> select2(ll i, ll j) {
    if (j - i < 2) {
      throw std::runtime_error("Random.select2: range too small");
    }
    ll x = range(i, j);
    ll y = range(i, j - 1);
    if (y >= x) ++y;
    if (x > y) swap(x, y);
    return {x, y};
  }

  template<typename RandomIt>
  void shuffle(RandomIt first, RandomIt last) { std::shuffle(first, last, rng); }

};

random_device Random::the_random_device;

// ---- end random.cc

// @@ !! LIM -- end mark --

const ll OP_SWAP = 0;
const ll OP_MOVE = 1;

vector<pll> nbr4{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pll> nbr8{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  Random rand;

  ll N; cin >> N;
  // @InpGrid(N, N, A) [Tm9WNXWV]
  auto A = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [Tm9WNXWV]

  vector<pll> ptOrd(N * N);
  vector ordPt(N, vector<ll>(N));
  REP(i, 0, N) REP(j, 0, N) {
    if (i % 2 == 0) ptOrd[i * N + j] = pll(i, j);
    else            ptOrd[i * N + j] = pll(i, N - 1 - j);
  }
  auto valOrd = [&](ll i) -> ll& { return ordPt[ptOrd[i].first][ptOrd[i].second]; };
  REP(i, 0, N*N) valOrd(i) = i;

  auto adj = [&](ll i, ll j) -> bool {
    assert(i != j);
    auto [ri, ci] = ptOrd[i];
    auto [rj, cj] = ptOrd[j];
    return abs(ri - rj) <= 1 and abs(ci - cj) <= 1;
  };

  auto selectCand = [&]() -> tuple<ll, ll, ll> {
    while (true) {
      auto onbrd = [&](ll r, ll c) -> bool { return 0 <= r and r < N and 0 <= c and c < N; };
      ll i0 = rand.range(0, N * N);
      auto [r0, c0] = ptOrd[i0];
      using sta = tuple<ll, ll, ll>;
      vector<sta> cands;
      for (auto p : nbr4) {
        ll r1 = r0 + p.first;
        ll c1 = c0 + p.second;
        if (not onbrd(r1, c1)) continue;
        ll i1 = ordPt[r1][c1];
        if (abs(i0 - i1) < 2) continue;
        if (i0 - 1 >= 0 and not adj(i0 - 1, i1)) continue;
        if (i0 + 1 <  N and not adj(i0 + 1, i1)) continue;
        if (i1 - 1 >= 0 and not adj(i1 - 1, i0)) continue;
        if (i1 + 1 <  N and not adj(i1 + 1, i0)) continue;
        cands.emplace_back(OP_SWAP, i0, i1);
      }
      if (not (i0 - 1 >= 0 and i0 + 1 < N and not adj(i0 - 1, i0 + 1))) {
        for (auto p : nbr8) {
          ll r1 = r0 + p.first;
          ll c1 = c0 + p.second;
          if (not onbrd(r1, c1)) continue;
          ll i1 = ordPt[r1][c1];
          assert(i1 != i0);
          if (i1 == i0 + 1) continue;
          if (i1 - 1 >= 0 and not adj(i1 - 1, i0)) continue;
          cands.emplace_back(OP_MOVE, i0, i1);
        }
      }
      if (not cands.empty()) {
        ll i = rand.range(0, ssize(cands));
        auto [op, a, b] = cands[i];
        assert(a != b);
        if (op == OP_SWAP and a > b) swap(a, b);
        return {op, a, b};
      }
    }
  };

  double TempS = 1000;
  double TempE = 10;
#if DEBUG
  ll rep = 100000;
#else
  ll rep = 1000000;
#endif
  REP(_r, 0, rep) {
    double TempNow = pow(TempE, (double)_r / rep) * pow(TempS, 1.0 - (double)_r / rep);
    auto thr = [&](ll cimpr) -> double { return exp(-abs(cimpr) / TempNow); };
    auto [op, a, b] = selectCand();
    ll cimpr;
    if (op == OP_SWAP) {
      assert(a < b);
      cimpr = (b - a) * valOrd(a) + (a - b) * valOrd(b);
    }else if (op == OP_MOVE) {
      if (a < b) {
        ll s = 0;
        REP(i, a + 1, b) s += valOrd(i);
        cimpr = (b - 1 - a) * valOrd(a) - s;
      }else if (b < a) {
        ll s = 0;
        REP(i, b, a) s += valOrd(i);
        cimpr = s - (a - b) * valOrd(a);
      }else assert(0);
    }else assert(0);
    if (cimpr >= 0 or rand.rand(0.0, 1.0) < thr(cimpr)) {
      if (op == OP_SWAP) {
        pll pa = ptOrd[a], pb = ptOrd[b];
        ptOrd[a] = pb; ptOrd[b] = pa; 
        ordPt[pa.first][pa.second] = b;
        ordPt[pb.first][pb.second] = a;
      }else if (op == OP_MOVE) {
        assert(a + 1 != b);
        pll pa = ptOrd[a];
        if (a < b) {
          REP(i, a + 1, b) ptOrd[i - 1] = ptOrd[i]; 
          ptOrd[b - 1] = pa;
          REP(i, a, b) valOrd(i) = i;
        }else if (b < a) {
          REPrev(i, a - 1, b) ptOrd[i + 1] = ptOrd[i];
          ptOrd[b] = pa;
          REP(i, b, a + 1) valOrd(i) = i;
        }else assert(0);
      }else assert(0);
    }
  }
  REP(i, 0, N * N) {
    auto [r, c] = ptOrd[i];
    cout << r << " " << c << "\n";
  }

  return 0;
}

