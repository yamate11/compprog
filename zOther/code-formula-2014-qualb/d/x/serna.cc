#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <class T> struct StarrySkyTree {
  private:
    int N, log, size;
    vector<T> node;
    void init() {
        log = 1;
        while ((1 << log) < N + 1) ++log;
        size = 1 << log;
        node.assign(size << 1, -inf<T>);
    }
    T _star(int i) {
        T mx = max(node[i << 1 | 0], node[i << 1 | 1]);
        node[i << 1 | 0] -= mx;
        node[i << 1 | 1] -= mx;
        return mx;
    }
    void star(int i) {
        node[i] += _star(i);
    }

  public:
    StarrySkyTree(int n) : N(n) {
        init();
    }
    StarrySkyTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = a[i];
        for (int i = size - 1; i >= 1; --i) node[i] = _star(i);
    }
    T operator[](int i) {
        T ans = node[i += size];
        while (i >>= 1) ans += node[i];
        return ans;
    }
    T get(int l, int r) {
        assert(l < r);
        if (l == 0 and r == N) return node[1];
        stack<int> L, R;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L.push(l++);
            if (r & 1) R.push(--r);
        }
        vector<T> leaf;
        T commonL = node[1];
        for (int i = l - 1; i > 1; i >>= 1) commonL += node[i];
        for (int i = l - 1; !L.empty();) {
            i = (i << 1 | 1);
            if (i == L.top()) {
                leaf.push_back(commonL + node[i--]);
                L.pop();
            }
            commonL += node[i];
        }
        T commonR = node[1];
        for (int i = r; i > 1; i >>= 1) commonR += node[i];
        for (int i = r; !R.empty();) {
            i = (i << 1 | 0);
            if (i == R.top()) {
                leaf.push_back(commonR + node[i++]);
                R.pop();
            }
            commonR += node[i];
        }
        return *max_element(leaf.begin(), leaf.end());
    }
    T top() {
        return node[1];
    }
    void apply(int l, int r, const T &x) {
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) node[l++] += x;
            if (r & 1) node[--r] += x;
            if ((l - 1) > 1) star((l - 1) >> 1);
            if (r < (size << 1)) star(r >> 1);
        }
        for (int i = l - 1; i > 1; i >>= 1) star(i);
        assert(r < size << 1);
        for (int i = r; i >= 1; i >>= 1) star(i);
    }
};
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N, 0);
    StarrySkyTree<int> sst(A);
    while (Q--) {
        int q, s, t;
        cin >> q >> s >> t;
        t++;
        if (q == 0) {
            int x;
            cin >> x;
            sst.apply(s, t, -x);
        }
        if (q == 1) {
            cout << -sst.get(s, t) << endl;
        }
    }
}

