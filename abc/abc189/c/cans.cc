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

// @@ !! LIM(cartesianProd f:updMaxMin)

// ---- inserted library file cartesianProd.cc

template<typename T>
struct CartesianProduct {
  int root;
  vector<int> left;
  vector<int> right;

  CartesianProduct() : root(-1), left(), right() {}
  template<class R, class Cmp = std::less<T>>
  explicit CartesianProduct(const R& vec, Cmp comp = Cmp{}) { build(vec, comp); }

  template<class R, class Cmp = std::less<T>>
  void build(const R& vec, Cmp comp = Cmp{}) {
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

template<class R>
CartesianProduct(const R&) -> CartesianProduct<typename R::value_type>;
template<class R, class Cmp>
CartesianProduct(const R&, Cmp) -> CartesianProduct<typename R::value_type>;

// ---- end cartesianProd.cc

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

  ll N; cin >> N;
  // @InpVec(N, A) [DaVgkRpg]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [DaVgkRpg]
  CartesianProduct cp(A);
  
  ll ans = 0;
  auto dfs = [&](auto rF, ll lo, ll hi, ll x) -> void {
    if (x < 0) return;
    updMax(ans, (hi - lo) * A[x]);
    rF(rF, lo, x, cp.left[x]);
    rF(rF, x + 1, hi, cp.right[x]);
  };
  dfs(dfs, 0, N, cp.root);
  cout << ans << endl;

  return 0;
}

