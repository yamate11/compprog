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
  // @InpVec(N, S, type=string) [ySGz8v8q]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [ySGz8v8q]
  sort(ALL(S));
  vector<ll> A(N - 1);
  REP(i, 0, N - 1) {
    ll x = 0;
    REP(j, 0, min(ssize(S[i]), ssize(S[i + 1]))) {
      if (S[i][j] == S[i + 1][j]) x++;
      else break;
    }
    A[i] = x;
  }
  CartesianTree ct(A);
  ll ans = 0;
  auto f = [&](auto rF, ll lo, ll hi, ll x) -> void {
    if (x < 0) return;
    ans += A[x] * (x - lo + 1) * (hi - x);
    rF(rF, lo, x, ct.left[x]);
    rF(rF, x + 1, hi, ct.right[x]);
  }; 
  f(f, 0, N - 1, ct.root);
  cout << ans << endl;
  return 0;
}

