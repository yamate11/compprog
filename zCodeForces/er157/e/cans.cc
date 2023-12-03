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

// @@ !! LIM(FuncGraph f:updMaxMin)

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

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

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
    
    ll big = 1e10;
    auto f1 = [&](auto& mp, ll a, ll d) -> void {
      auto it = mp.find(a);
      if (it == mp.end()) mp[a] = d;
      else updMax(it->second, d);
    };
    map<ll, ll> mpA, mpB;
    REP(i, 0, N) f1(mpA, AX[i], AY[i]);
    REP(i, 0, M) f1(mpB, BX[i], BY[i]);
    mpA[big] = -1;
    mpB[big] = -1;

    ll seq = 2;
    vector enc(2, vector(1e6 + 1, -1LL));
    auto get_seq = [&](int sw, ll x) -> ll {
      if (x == big) return sw == 0 ? 0 : 1;
      ll& ref = enc[sw][x];
      if (ref < 0) ref = seq++;
      return ref;
    };

    vector<ll> t_fg;
    auto store_t_fg = [&](ll a, ll b) -> void {
      if (a >= SIZE(t_fg)) t_fg.resize(a + 1);
      t_fg[a] = b;
    };
    for (auto [a, d] : mpA) {
      if (a == big) continue;
      ll eA = get_seq(0, a);
      auto it = mpB.upper_bound(d);
      ll eB = get_seq(1, it->first);
      store_t_fg(eA, eB);
    }
    for (auto [a, d] : mpB) {
      if (a == big) continue;
      ll eB = get_seq(1, a);
      auto it = mpA.upper_bound(d);
      ll eA = get_seq(0, it->first);
      store_t_fg(eB, eA);
    }
    store_t_fg(get_seq(0, big), get_seq(0, big));
    store_t_fg(get_seq(1, big), get_seq(1, big));
    ll K = SIZE(t_fg);
    FuncGraph fg(K);
    REP(k, 0, K) fg.add_edge(k, t_fg[k]);
    fg.build();
    
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    REP(i, 0, N) {
      auto it = mpB.upper_bound(AY[i]);
      ll eB = get_seq(1, it->first);
      ll z = fg.node_on_cycle(eB);
      if (z == get_seq(1, big)) ans1++;
      else if (z == get_seq(0, big)) ans3++;
      else ans2++;
    }
    cout << ans1 << " " << ans2 << " " << ans3 << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

