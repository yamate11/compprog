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

// @@ !! LIM()

// ---- inserted library file cartesianTree.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/cartesianTree.cc


// ---- end cartesianTree.cc

// @@ !! LIM -- end mark --

template<typename Ctn, typename Comp = less<typename Ctn::value_type>, bool comp_arg_index = false>
struct CartesianTree {
  int root;
  vector<int> left;
  vector<int> right;
  vector<int> parent;

  CartesianTree() : root(-1), left(), right(), parent() {}
  CartesianTree(const Ctn& vec, Comp comp = Comp()) { build(vec, comp); }

  void build(const Ctn& vec, Comp comp = Comp()) {
    auto comp_idx = [&](int a, int b) -> bool {
      if constexpr (comp_arg_index) return comp(a, b);
      else return comp(vec[a], vec[b]);
    };

    int n = ssize(vec);
    root = -1;
    left = vector<int>(n, -1);
    right = vector<int>(n, -1);
    parent = vector<int>(n, -1);
    vector<int> stack{-1};
    for (int i = 0; i < n; i++) {
      int left_cand = -1;
      while (true) {
        if (int j = stack.back(); j == -1 or comp_idx(j, i)) {
          left[i] = left_cand;
          if (left_cand >= 0) parent[left_cand] = i;

          if (j == -1) root = i;
          else {
            right[j] = i;
            parent[i] = j;
          }

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

template<typename Ctn, typename Comp = less<typename Ctn::value_type>>
auto make_cartesian_tree(const Ctn& vec, Comp comp = Comp()) {
  return CartesianTree<Ctn, Comp, false>(vec, comp);
}
template<typename Ctn, typename Comp>
auto make_cartesian_tree_comp_index(const Ctn& vec, Comp comp) {
  return CartesianTree<Ctn, Comp, true>(vec, comp);
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, H) [OM9F2sjo]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [OM9F2sjo]
  // @InpMVec(Q, ((L, dec=1), (R, dec=1))) [LmYKvsNi]
  auto L = vector(Q, ll());
  auto R = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; v2 -= 1; R[i] = v2;
  }
  // @End [LmYKvsNi]

  auto comp = [&](ll i, ll j) -> bool {
    if (H[i] != H[j]) return H[i] > H[j];
    return i > j;
  };
  auto ct = make_cartesian_tree_comp_index(H, comp);

  vector<ll> ans(Q);
  vector revL(N, vector<ll>());
  REP(q, 0, Q) revL[L[q]].push_back(q);

  vector<ll> st;
  auto dfs = [&](auto rF, ll nd) -> void {
    st.push_back(nd);
    for (ll q : revL[nd]) {
      ll num = st.end() - ranges::lower_bound(st, R[q], greater<ll>());
      ans[q] = num;
    }
    if (ct.left[nd] >= 0) rF(rF, ct.left[nd]);
    st.pop_back();
    if (ct.right[nd] >= 0) rF(rF, ct.right[nd]);
  };
  dfs(dfs, ct.root);
  REPOUT(q, 0, Q, ans[q], "\n");

  return 0;
}

