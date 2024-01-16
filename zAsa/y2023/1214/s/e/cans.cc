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

// @@ !! LIM(FuncGraph)

// ---- inserted library file FuncGraph.cc

struct FuncGraph {
  int size;
  vector<int> fwd;
  vector<int> _cc;
  vector<int> _cc_size;
  vector<int> _cycle_size;
  vector<int> _on_cycle;
  vector<int> _dp;
  bool _built;

  FuncGraph(int size_) : size(size_), fwd(size), _cc(size, -1), _cc_size(), _cycle_size(),
                         _on_cycle(size), _dp(size, -1), _built(false) {}

  void add_edge(int i, int j) {
    fwd[i] = j;
  };

  int _set_depth(int i) {
    if (_dp[i] < 0) {
      if (_on_cycle[i] == i) _dp[i] = 0;
      else _dp[i] = _set_depth(fwd[i]) + 1;
    }
    return _dp[i];
  }

  void build() {
    if (_built) throw runtime_error("FuncGraph: built() should be called at most once.");
    for (int i = 0; i < size; i++) {
      if (_cc[i] < 0) {
        int tmpidx = _cc_size.size();
        vector<int> stack;
        int k;
        for (k = i; _cc[k] < 0; k = fwd[k]) {
          _cc[k] = tmpidx;
          stack.push_back(k);
        }
        if (_cc[k] == tmpidx) {
          _cc_size.push_back(stack.size());
          bool on = true;
          while (not stack.empty()) {
            int m = stack.back(); stack.pop_back();
            _on_cycle[m] = on ? m : k;
            if (m == k) {
              _cycle_size.push_back(_cc_size[tmpidx] - stack.size());
              on = false;
            }
          }
        }else {
          _cc_size[_cc[k]] += stack.size();
          while (not stack.empty()) {
            int m = stack.back(); stack.pop_back();
            _on_cycle[m] = _on_cycle[k];
            _cc[m] = _cc[k];
          }
        }
      }
    }
    for (int i = 0; i < size; i++) _set_depth(i);
    _built = true;
  }

  int numcc() {
    if (not _built) build();
    return (int)_cc_size.size();
  }

  int ccid(int i) {
    if (not _built) build();
    return _cc[i];
  }

  int cc_size(int i) {
    if (not _built) build();
    return _cc_size[ccid(i)];
  }

  int cycle_size(int i) {
    if (not _built) build();
    return _cycle_size[ccid(i)];
  }

  int node_on_cycle(int i) {
    if (not _built) build();
    return _on_cycle[i];
  }

  bool is_on_cycle(int i) {
    if (not _built) build();
    return _dp[i] == 0;
  }

  int dist_to_cycle(int i) {
    return _dp[i];
  }

};

// ---- end FuncGraph.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X, M; cin >> N >> X >> M;
  FuncGraph fg(M);
  for (ll i = 0; i < M; i++) fg.add_edge(i, (i * i) % M);
  fg.build();

  if (N <= 1e6) {
    ll ans = 0;
    ll a = X;
    REP(i, 0, N) {
      ans += a;
      a = (a * a) % M;
    }
    cout << ans << endl;
    return 0;
  }
  ll csz = fg.cycle_size(X);
  ll len = fg.dist_to_cycle(X);
  ll sum1 = 0;
  ll a = X;
  REP(i, 0, len) {
    sum1 += a;
    a = (a * a) % M;
  }
  ll sum2 = 0;
  REP(i, 0, csz) {
    sum2 += a;
    a = (a * a) % M;
  }
  ll p = (N - len) / csz;
  ll q = (N - len) % csz;
  ll sum3 = 0;
  REP(i, 0, q) {
    sum3 += a;
    a = (a * a) % M;
  }
  ll ans = sum1 + sum2 * p + sum3;
  cout << ans << endl;

  return 0;
}

