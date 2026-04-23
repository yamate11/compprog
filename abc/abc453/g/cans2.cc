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

template<typename T, typename add_t>
struct PersSegTree {
  struct Node {
    Node* left;
    Node* right;
    T val;
    Node(Node* left_ = nullptr, Node* right_ = nullptr, const T& val_ = T()) : left(left_), right(right_), val(val_) {}
  };

  T unitT;
  add_t add;
  ll size;

  PersSegTree(const T& unitT_, add_t add_) : unitT(unitT_), add(add_) {}

  Node* _from_two(Node* nd1, Node* nd2) { return new Node(nd1, nd2, add(nd1->val, nd2->val)); }

  Node* fromVector(const vector<T>& vec) {
    auto sub = [&](auto rF, ll lo, ll hi) -> Node* {
      if (lo + 1 == hi) return new Node(nullptr, nullptr, vec[lo]);
      else {
        ll mid = (lo + hi) / 2;
        return _from_two(rF(rF, lo, mid), rF(rF, mid, hi));
      }
    };
    size = ssize(vec);
    return sub(sub, 0, size);
  }

  T query(Node* root, ll rngLo, ll rngHi) const {
    if (rngHi <= rngLo) return unitT;
    auto sub = [&](auto rF, Node* nd, ll lo, ll hi) -> T {
      if (rngHi <= lo) return unitT;
      if (hi <= rngLo) return unitT;
      if (rngLo <= lo and hi <= rngHi) return nd->val;
      ll mid = (lo + hi) / 2;
      return add(rF(rF, nd->left, lo, mid), rF(rF, nd->right, mid, hi));
    };
    return sub(sub, root, 0, size);
  }

  Node* set(Node* root, ll i, const T& t) {
    auto sub = [&](auto rF, Node* nd, ll lo, ll hi) -> Node* {
      if (lo + 1 == hi) {
        assert(i == lo);
        return new Node(nullptr, nullptr, t);
      }else {
        ll mid = (lo + hi) / 2;
        if (i < mid) return _from_two(rF(rF, nd->left, lo, mid), nd->right);
        else         return _from_two(nd->left, rF(rF, nd->right, mid, hi));
      }
    };
    return sub(sub, root, 0, size);
  }
};

template<typename T>
auto make_pers_seg_tree(const T& unitT, auto add, const vector<T>& init_vec) {
  auto pst = PersSegTree<T, decltype(add)>(unitT, add);
  auto root = pst.fromVector(init_vec);
  return make_pair(move(pst), move(root));
}


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, Q; cin >> N >> M >> Q;
  auto [pst, root] = make_pers_seg_tree(0LL, plus<ll>(), vector<ll>(M));
  vector<decltype(root)> vec(N, root);
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x, y; cin >> x >> y; x--; y--;
      vec[x] = vec[y];
    }else if (tp == 2) {
      ll x, y, z; cin >> x >> y >> z; x--; y--;
      vec[x] = pst.set(vec[x], y, z);
    }else if (tp == 3) {
      ll x, l, r; cin >> x >> l >> r; x--; l--;
      cout << pst.query(vec[x], l, r) << "\n";
    }
  }

  return 0;
}

