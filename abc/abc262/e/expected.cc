#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

using mint = atcoder::modint998244353;

mint fact(const int n) {
    static vector<mint> v = {1};
    while ((int)v.size() <= n) {
        v.push_back(v.back() * v.size());
    }
    return v[n];
}

mint inv_fact(const int n) {
    static vector<mint> u = {0, 1}, v = {1, 1};
    for (int i = (int)u.size(); i <= n; ++i) {
        u.push_back(-mint(mint::mod() / i) * u[mint::mod() % i]);
        v.push_back(v.back() * u.back());
    }
    return v[n];
}

mint binom(const int n, const int k) {
    return fact(n) * inv_fact(k) * inv_fact(n - k);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> deg(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        deg[u] += 1, deg[v] += 1;
    }
    int odd = 0;
    for (const int x : deg) {
        if (x % 2 == 1) {
            odd += 1;
        }
    }
    mint ans = 0;
    for (int i = 0; i <= k; i += 2) {
        if (i <= odd and k - i <= n - odd) {
            ans += binom(odd, i) * binom(n - odd, k - i);
        }
    }
    cout << ans.val() << '\n';
    return 0;
}
