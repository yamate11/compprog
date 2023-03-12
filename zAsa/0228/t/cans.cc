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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(f:perfmeas)

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto func = [](size_t lsz1, size_t lsz2) -> pll {
    // constexpr int rep = 1 << 6;
    size_t sz1 = 1 << lsz1;
    size_t sz2 = 1 << lsz2;
    double t0a = get_time_sec();
    // vector va(sz1, vector(sz2, 0));
    double t1a = get_time_sec();
    // vector vb(sz2, vector(sz1, 0));
    double t2a  = get_time_sec();
    cerr << "  " << llround((t1a - t0a) * 1000000) << " " << llround((t2a - t1a) * 1000000) << endl;
    double t0 = get_time_sec();
    {
      // for (size_t r = 0; r < rep; r++) {
      vector va(sz1, vector(sz2, 0));
        for (size_t i = 0; i < sz1; i++) {
          for (size_t j = 0; j < sz2; j++) {
            va[i][j] = i + j;
          }
        }
        // }
    }
    double t1 = get_time_sec();
    {
      // for (size_t r = 0; r < rep; r++) {
      vector vb(sz2, vector(sz1, 0));
        for (size_t i = 0; i < sz1; i++) {
          for (size_t j = 0; j < sz2; j++) {
            vb[j][i] = i + j;
          }
        }
        // }
    }
    double t2 = get_time_sec();
    return pll(llround((t1 - t0) * 1000000), llround((t2 - t1) * 1000000));
  };

  vector<pll> tset{{18, 1}, {18, 2}, {18, 3}, {18, 4},
                   {1, 18}, {2, 18}, {3, 18}, {4, 18},
                   {14, 2}, {16, 2}, {18, 2}, {20, 2},
                   {2, 14}, {2, 16}, {2, 18}, {2, 20},
                   {9, 9}, {10, 10}, {11, 11},
                   {12, 1}, {12, 2}, {12, 3}, {12, 4}, {12, 5}, {12, 6}, {12, 7}, {12, 8}, {12, 9}, {12, 10}, {12, 11}
  };
  for (auto [sz1, sz2] : tset) {
    auto [t1, t2] = func(sz1, sz2);
    cout << sz1 << " " << sz2 << " " << t1 << " " << t2 << endl;
  }


  return 0;
}

