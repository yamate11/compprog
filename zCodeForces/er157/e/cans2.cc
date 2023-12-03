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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, AX) [XHj2hXKb]
    auto AX = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; AX[i] = v; }
    // @End [XHj2hXKb]
    // @InpVec(N, AY) [yKQX9lpp]
    auto AY = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; AY[i] = v; }
    // @End [yKQX9lpp]
    ll M; cin >> M;
    // @InpVec(M, BX) [9dtMsl4k]
    auto BX = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; BX[i] = v; }
    // @End [9dtMsl4k]
    // @InpVec(M, BY) [uJ23atJg]
    auto BY = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; BY[i] = v; }
    // @End [uJ23atJg]
    
    auto func = [&](ll n, auto& vx, auto& vy) -> vector<pll> {
      vector<pll> tmp, ret;
      REP(i, 0, n) tmp.emplace_back(vy[i], vx[i]);
      sort(ALL(tmp), greater<pll>());
      for (auto [d, a] : tmp) {
        ll ca;
        if (ret.empty()) {
          ret.emplace_back(a, d);
          ca = a;
        }else {
          if (a <= ca) continue;
          ret.emplace_back(a, d);
          ca = a;
        }
      }
      return ret;
    };

    ll big = 1e10;
    auto EA = func(N, AX, AY);
    auto EB = func(M, BX, BY);

    auto func2 = [&](auto& ep, auto& eq) -> vector<ll> {
      ll K = SIZE(ep);
      vector<ll> ret(K);
      REP(i, 0, K) {
        auto [a, d] = ep[i];
        ll j = upper_bound(ALL(eq), pll(d, big)) - eq.begin();
        ret[i] = j;
      }
      return ret;
    };
    auto nAB = func2(EA, EB);
    auto nBA = func2(EB, EA);

    ll numA = SIZE(EA);
    ll numB = SIZE(EB);

    FuncGraph fg(numA + numB + 2);
    for (ll i = 0; i < numA; i++) {
      fg.add_edge(i, numA + 1 + nAB[i]);
    }
    for (ll i = 0; i < numB; i++) {
      fg.add_edge(numA + 1 + i, nBA[i]);
    }
    fg.add_edge(numA, numA);
    fg.add_edge(numA + 1 + numB, numA + 1 + numB);
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    REP(i, 0, N) {
      ll j = upper_bound(ALL(EB), pll(AY[i], big)) - EB.begin();
      ll p = fg.node_on_cycle(numA + 1 + j);
      if (p == numA + 1 + numB) ans1++;
      else if (p == numA) ans3++;
      else ans2++;
    }
    cout << ans1 << " " << ans2 << " " << ans3 << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

