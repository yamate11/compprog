#include <bits/stdc++.h>
using namespace std;
struct Mo {
    int n;
    vector<int> left, right;
    Mo(int n) : n(n) {}
    void add(int l, int r) {
        left.push_back(l);
        right.push_back(r);
    }
    template <typename A, typename D, typename REM>
    void run(const A& add, const D& del, const REM& rem) {
        const int q = left.size(), width = max<int>(1, int(sqrt(3) * n / sqrt(max(1, 2 * q))));
        vector<int> order(q);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            const int ablock = left[a] / width, bblock = left[b] / width;
            if (ablock != bblock) return ablock < bblock;
            return (ablock & 1) ? (right[a] > right[b]) : (right[a] < right[b]);
        });
        int l = 0, r = 0;
        for (auto idx : order) {
            while (l > left[idx]) add(--l);
            while (r < right[idx]) add(r++);
            while (l < left[idx]) del(l++);
            while (r > right[idx]) del(--r);
            rem(idx);
        }
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + (s[i] == 'W' ? 1 : -1);
    Mo mo(n);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--, r++;
        mo.add(l, r);
    }
    unordered_map<int, int> cnt;
    long long res = 0;
    vector<long long> ans(q);
    auto add = [&](int k) -> void {
        res += cnt[sum[k] - 1] + cnt[sum[k]] + cnt[sum[k] + 1];
        cnt[sum[k]]++;
    };
    auto del = [&](int k) -> void {
        cnt[sum[k]]--;
        res -= cnt[sum[k] - 1] + cnt[sum[k]] + cnt[sum[k] + 1];
    };
    auto rem = [&](int k) -> void {
        ans[k] = res;
    };
    mo.run(add, del, rem);
    for (int i = 0; i < q; ++i) cout << ans[i] << endl;
}
