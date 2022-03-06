#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) {cin >> A[i]; A[i]--; }

  using T = ll;

  int Q; cin >> Q;
  auto body = [&]() -> void {

  struct state_t {
    vector<ll> vec;
    ll num_pairs;
    inline state_t() : vec(1e5), num_pairs(0) {}
    inline void add(T x) {
      if (++vec[x] % 2 == 0) num_pairs++;
    }
    inline void subtract(T x) {
      if (--vec[x] % 2 != 0) num_pairs--;
    }
    inline T value() { return num_pairs; }
  };

    // ブロック数
    int K = lround(sqrt(Q));

    // クエリの先読み
    using tup_t = tuple<int, int, int, int>; // ブロックID, r, l, クエリID
    vector<tup_t> qs(Q);
    for (int query_id = 0; query_id < Q; query_id++) {
      int l, r; cin >> l >> r; l--;       // 添字0開始，半開区間
      int block_id = l / K;
      qs.emplace_back(block_id, r, l, query_id);
    }

    // 重要: ソートを忘れない!
    sort(qs.begin(), qs.end());          

    // メイン
    vector<T> ans(Q);
    state_t state = state_t();  // 現在のクエリの状態を初期化
    int cl = 0, cr = 0;         // 現在の l, r の値
    for (auto [_not_used, r, l, query_id] : qs) {
      while (l < cl) {      // 左側が拡張
        --cl;
        state.add(A[cl]);
      }
      while (cr < r) {      // 右側が拡張
        state.add(A[cr]);
        cr++;
      }
      while (cl < l) {      // 左側が縮小
        state.subtract(A[cl]);
        cl++;
      }
      while (r < cr) {      // 右側が縮小
        cr--;
        state.subtract(A[cr]);
      }
      ans[query_id] = state.value();
    }

    for (T a : ans) cout << a << "\n";   // 答の出力
  };

  body();
  return 0;
}

