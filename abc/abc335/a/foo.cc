#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> c(Q);
    for (int i = 0; i < Q; i++) {
        cin >> c[i];
        c[i]--;
    }
    auto modpow = [](long long a, long long n, long long mod) -> long long {
        long long res = 1;
        while (n > 0) {
            if (n & 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    };
    vector<long long> S(N);
    for (int i = 0; i <= N; i++) {
        S[i + 1] = S[i] + modpow(a[i], a[i + 1], MOD);
    }
    long long ans = 0;
    int cur = 0;
    for (int i = 0; i < Q; i++) {
        ans += abs(S[c[i]] - S[cur]);
        ans %= MOD;
        cur = c[i];
    }
    ans += S[cur];
    cout << ans << endl;
}
