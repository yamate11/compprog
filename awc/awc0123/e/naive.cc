#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
    }
    vector<int> st;
    st.emplace_back(0);
    vector<vector<int>> s(k);
    vector<int> p(k);
    for (int i = 0; i < k; ++i) {
        int sz;
        cin >> sz;
        s[i].resize(sz);
        for (int j = 0; j < sz; ++j) {
            cin >> s[i][j];
            s[i][j]--;
            st.emplace_back(s[i][j]);
        }
        cin >> p[i];
    }
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    vector<int> id(n, -1);
    for (int i = 0; i < (int)st.size(); ++i) id[st[i]] = i;
    vector<vector<int>> table(st.size(), vector<int>(st.size(), t + 1));
    for (int i = 0; i < (int)st.size(); ++i) {
        vector<int> dist(n, t + 1);
        dist[st[i]] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, st[i]);
        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (dist[v] != d) continue;
            for (auto [u, w] : g[v]) {
                if (dist[u] > d + w) {
                    dist[u] = d + w;
                    pq.emplace(dist[u], u);
                }
            }
        }
        for (int j = 0; j < (int)st.size(); ++j) table[i][j] = dist[st[j]];
    }
    vector<vector<int>> dp(1 << (int)st.size(), vector<int>(st.size(), t + 1));
    dp[1 << id[0]][id[0]] = 0;
    for (int bit = 0; bit < (1 << (int)st.size()); ++bit) {
        for (int i = 0; i < (int)st.size(); ++i) {
            if (!((bit >> i) & 1)) continue;
            if (dp[bit][i] == t + 1) continue;
            for (int j = 0; j < (int)st.size(); ++j) {
                if ((bit >> j) & 1) continue;
                if (dp[bit | 1 << j][j] > dp[bit][i] + table[i][j]) {
                    dp[bit | 1 << j][j] = dp[bit][i] + table[i][j];
                }
            }
        }
    }
    vector<long long> reward(1 << (int)st.size(), 0);
    for (int bit = 0; bit < (int)1 << st.size(); ++bit) {
        for (int i = 0; i < k; ++i) {
            bool flag = true;
            for (auto e : s[i])
                if (!((bit >> id[e]) & 1)) {
                    flag = false;
                    break;
                }
            if (flag) reward[bit] += p[i];
        }
    }
    long long ans = 0;
    for (int bit = 0; bit < (int)1 << st.size(); ++bit) {
        for (int i = 0; i < (int)st.size(); ++i)
            if (dp[bit][i] <= t) ans = max(ans, reward[bit]);
    }
    cout << ans << endl;
}
