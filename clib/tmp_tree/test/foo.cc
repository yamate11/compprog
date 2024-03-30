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

// @@ !! LIM(f:perfmeas random)

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

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

};

random_device Random::the_random_device;

// ---- end random.cc

// @@ !! LIM -- end mark --


int main(int argc, char** argv) {
  
  Random rand;
  
  ll rep = atoi(argv[1]);
  ll tree_type = atoi(argv[2]);
  ll tp = atoi(argv[3]);

  ll N = 1LL << rep;
  vector<vector<ll>> nbr(N);
  REP(i, 1, N) {
    ll j;
    if (tree_type == 1) {
      j = rand.range(0, i);
    }else {
      j = i - 1;
    };
    nbr[i].push_back(j);
    nbr[j].push_back(i);
  }
  // ll root = rand.range(0, N);
  ll root = 0;
  vector<ll> vec(N, 1LL);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    for (ll c : nbr[nd]) {
      if (c == pt) continue;
      rF(rF, c, nd);
      vec[nd] += vec[c];
    }
  };
  ll maxsidx = 0;
  ll sidx = 0;
  auto nonrc = [&]() -> void {
    vector<pair<ll, ll>> stack;
    stack.emplace_back(root, 0);
    while (sidx >= 0) {
      auto& [nd, cidx] = stack[sidx];
      if (cidx == ssize(nbr[nd])) {
        if (sidx >= 1) vec[stack[sidx - 1].first] += vec[nd];
        sidx--;
      }else {
        if (sidx >= 1 and stack[sidx - 1].first == nbr[nd][cidx]) cidx++;
        else {
          sidx++;
          maxsidx = max(maxsidx, sidx);
          if (sidx == ssize(stack)) stack.emplace_back(nbr[nd][cidx++], 0);
          else {
            stack[sidx].first = nbr[nd][cidx++];
            stack[sidx].second = 0;
          }
        }
      }
    }
    cerr << "maxsidx " << maxsidx << endl;
  };

  double t1 = get_time_sec();
  if (tp == 1) {
    dfs(dfs, root, -1);
  }else if (tp == 2) {
    nonrc();
  }
  double t2 = get_time_sec();
  cout << t2 - t1 << endl;
  ll dummy = 0;
  REP(i, 0, N) dummy += vec[i];
  cerr << dummy << endl;
}
