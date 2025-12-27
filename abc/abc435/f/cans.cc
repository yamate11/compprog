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

  ll N; cin >> N;
  // @InpVec(N, P, dec=1) [9clFGDoQ]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [9clFGDoQ]
  REP(i, 0, N) P[i] = -P[i];

  CartesianTree ct(P);
  vector<ll> weight(N, 0LL);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    if (nd != ct.root) {
      weight[nd] = weight[pt] + abs(pt - nd);
    }
    if (ct.left[nd] >= 0) rF(rF, ct.left[nd], nd);
    if (ct.right[nd] >= 0) rF(rF, ct.right[nd], nd);
  };
  dfs(dfs, ct.root, -1);
  cout << *max_element(ALL(weight)) << endl;

  return 0;
}

