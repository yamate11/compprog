#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
int main() {
    string T;
    cin >> T;
    int t = T.size();
    int N;
    cin >> N;
    vector<vector<string>> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i].resize(a);
        for (int j = 0; j < a; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> dp(N + 1, vector<int>(t + 1, inf<int>));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < t; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            for (auto &&S : A[i]) {
                int s = S.size();
                auto p = T.find(S);
                while (p != string::npos) {
                    dp[i + 1][p + s] = min(dp[i + 1][p + s], dp[i][p] + 1);
                    p = T.find(S, p + 1);
                }
            }
        }
    }
    if (dp[N][t] == inf<int>) {
        cout << -1 << endl;
    } else {
        cout << dp[N][t] << endl;
    }
}
