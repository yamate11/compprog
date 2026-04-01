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

// @@ !! LIM(cartesianTree)

// ---- inserted library file cartesianTree.cc

template<typename T>
struct CartesianTree {
  int root;
  vector<int> left;
  vector<int> right;

  CartesianTree() : root(-1), left(), right() {}
  template<typename Comp = less<typename T::value_type>>
  CartesianTree(const T& vec, Comp comp = Comp()) { build(vec, comp); }

  template<typename Comp = less<typename T::value_type>>
  void build(const T& vec, Comp comp = Comp()) {
    int n = ssize(vec);
    root = -1;
    left = vector<int>(n, -1);
    right = vector<int>(n, -1);
    vector<int> stack{-1};
    for (int i = 0; i < n; i++) {
      int left_cand = -1;
      while (true) {
        if (int j = stack.back(); j == -1 or comp(vec[j], vec[i])) {
          left[i] = left_cand;
          if (j == -1) root = i;
          else         right[j] = i;
          stack.push_back(i);
          break;
        }else {
          left_cand = j;
          stack.pop_back();
        }
      }
    }
  }
};

// ---- end cartesianTree.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, H; cin >> N >> H;
    // @InpVec(N, A, dec=0) [4kFUbICt]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 0; A[i] = v; }
    // @End [4kFUbICt]

    CartesianTree ct(A, greater<ll>());
    vector<ll> parent(N, -1LL);
    REP(i, 0, N) {
      if (ct.left[i] >= 0) parent[ct.left[i]] = i;
      if (ct.right[i] >= 0) parent[ct.right[i]] = i;
    }
    auto dfs = [&](auto rF, ll lo, ll hi, ll nd, ll num) -> ll {
      ll pdep;
      if (nd == ct.root) pdep = H;
      else               pdep = A[parent[nd]];
      ll chL = ct.left[nd];
      ll chR = ct.right[nd];

      ll ret = (hi - lo) * (pdep - A[nd]);
      if (num == 1) {
        ll vL = 0, vR = 0;
        if (chL >= 0) vL = rF(rF, lo, nd, chL, 1);
        if (chR >= 0) vR = rF(rF, nd + 1, hi, chR, 1);
        ret += max(vL, vR);
        return ret;
      }else if (num == 2) {
        ll vL1 = 0, vL2 = 0, vR1 = 0, vR2 = 0;
        if (chL >= 0) {
          vL2 = rF(rF, lo, nd, chL, 2);
          vL1 = rF(rF, lo, nd, chL, 1);
        }
        if (chR >= 0) {
          vR2 = rF(rF, nd + 1, hi, chR, 2);
          vR1 = rF(rF, nd + 1, hi, chR, 1);
        }
        ret += max(vL1 + vR1, max(vL2, vR2));
        return ret;
      }else assert(0);
    };

    ll ans = dfs(dfs, 0, N, ct.root, 2);
    cout << ans << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

