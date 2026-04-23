#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <atcoder/all>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    int q;
    cin >> q;
    vector<tuple<int, int, int>> query(q);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        query[i] = {x, y, i};
    }

    int w = 1000;
    sort(query.begin(), query.end(), [w](const auto& a, const auto& b) {
        int block_a = get<0>(a) / w;
        int block_b = get<0>(b) / w;
        if (block_a != block_b) return block_a < block_b;
        return (block_a % 2 == 0) ? (get<1>(a) < get<1>(b)) : (get<1>(a) > get<1>(b));
    });

    vector<ll> s(A.begin(), A.end());
    s.insert(s.end(), B.begin(), B.end());
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    map<ll, int> d;
    int sz = s.size();
    for (int i = 0; i < sz; i++) d[s[i]] = i;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) a[i] = d[A[i]];
    for (int i = 0; i < n; i++) b[i] = d[B[i]];

    atcoder::fenwick_tree<ll> fta0(sz), ftb0(sz);
    atcoder::fenwick_tree<ll> fta1(sz), ftb1(sz);

    vector<ll> ans(q);
    int x = 0, y = 0;
    ll now = 0, asum = 0, bsum = 0;

    for (const auto& [xi, yi, i] : query) {
        while (x < xi) {
            ll c = ftb0.sum(0, a[x] + 1);
            ll s = ftb1.sum(0, a[x] + 1);
            now += y * A[x] + bsum - 2 * ((y - c) * A[x] + s);
            asum += A[x];
            fta0.add(a[x], 1);
            fta1.add(a[x], A[x]);
            x++;
        }
        while (x > xi) {
            x--;
            ll c = ftb0.sum(0, a[x] + 1);
            ll s = ftb1.sum(0, a[x] + 1);
            now -= y * A[x] + bsum - 2 * ((y - c) * A[x] + s);
            asum -= A[x];
            fta0.add(a[x], -1);
            fta1.add(a[x], -A[x]);
        }
        while (y < yi) {
            ll c = fta0.sum(0, b[y] + 1);
            ll s = fta1.sum(0, b[y] + 1);
            now += x * B[y] + asum - 2 * ((x - c) * B[y] + s);
            bsum += B[y];
            ftb0.add(b[y], 1);
            ftb1.add(b[y], B[y]);
            y++;
        }
        while (y > yi) {
            y--;
            ll c = fta0.sum(0, b[y] + 1);
            ll s = fta1.sum(0, b[y] + 1);
            now -= x * B[y] + asum - 2 * ((x - c) * B[y] + s);
            bsum -= B[y];
            ftb0.add(b[y], -1);
            ftb1.add(b[y], -B[y]);
        }
        ans[i] = now;
    }

    for (const auto& res : ans) cout << res << "\n";

    return 0;
}
