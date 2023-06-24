// submit 879754   2023-06-10 23:08:45 by Magentor

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define REP(i, n) for (long long i = 1; i < (long long)(n); i++)
typedef long long ll;
using mint = modint;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> s(n), a(m), b(m);
    rep(i, n) {
        cin >> s[i];
        s[i]--;
    }
    rep(i, m) { cin >> a[i]; }
    rep(i, m) { cin >> b[i]; }
    vector<vector<mint>> dp(n + 1, vector<mint>(k + 1, 0));
    dp[0][0] = 1;
    vector<vector<mint>> cum(n + 2, vector<mint>(k + 1, 0));
    cum[1][0] = 1;
    vector<ll> idx(m, 0);
    rep(i, n) {
        rep(j, k + 1) {
            if (0 <= j - a[s[i]]) {
                dp[i + 1][j] +=
                    cum[i + 1][j - a[s[i]]] - cum[idx[s[i]]][j - a[s[i]]];
            }
            if (0 <= j - b[s[i]]) {
                dp[i + 1][j] +=
                    cum[i + 1][j - b[s[i]]] - cum[idx[s[i]]][j - b[s[i]]];
            }
            cum[i + 2][j] = cum[i + 1][j] + dp[i + 1][j];
        }
        idx[s[i]] = i + 1;
    }
    mint ans = 0;
    rep(i, n) { ans += dp[i + 1][k]; }
    cout << ans.val() << endl;
}
