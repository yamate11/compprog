#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T, bool maximum_mode = false>
struct online_RMQ {
  int n = 0, levels = 0;
  vector<vector<T>> range_min;

  online_RMQ(const vector<T> &values = {}) {
    for (T value : values)
      add(value);
  }

  static int largest_bit(int x) {
    return 31 - __builtin_clz(x);
  }

  static T better(T a, T b) {
    return (a < b) ^ maximum_mode ? a : b;
  }

  void add(T value) {
    n++;

    if (largest_bit(n) + 1 > levels) {
      levels = largest_bit(n) + 1;
      range_min.emplace_back();
    }

    range_min[0].push_back(value);

    for (int k = 1; k < levels; k++) {
      int index = range_min[k].size();
      range_min[k].push_back(better(range_min[k - 1][index], range_min[k - 1][index + (1 << (k - 1))]));
    }
  }

  T query(int a, int b) const {
    assert(0 <= a && a < b && b <= n);
    int level = largest_bit(b - a);
    return better(range_min[level][a], range_min[level][b - (1 << level)]);
  }
};


const long long LL_INF = (long long) 2e18 + 5;

struct oper {
  int L, R, C;

  bool operator<(const oper &other) const {
    return R < other.R;
  }
};

int N, M;
vector<oper> ops;
vector<long long> dp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  ops.resize(M);

  for (oper &op : ops) {
    cin >> op.L >> op.R >> op.C;
    op.L--; op.R--;
  }

  sort(ops.begin(), ops.end());
  online_RMQ<long long> rmq;
  dp.assign(N, LL_INF);
  dp[0] = 0;

  for (oper &op : ops) {
    while (rmq.n < op.R)
      rmq.add(dp[rmq.n]);

    dp[op.R] = min(dp[op.R], rmq.query(op.L, op.R) + op.C);
  }

  cout << (dp[N - 1] < LL_INF ? dp[N - 1] : -1) << '\n';
}
