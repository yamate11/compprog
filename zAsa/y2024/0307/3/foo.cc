#include <bits/stdc++.h>
using namespace std;
#define mod(n) n %= MOD
const long long MOD = 4ll;
/**
 * mod二分累乗
 */
long long modpow(long long a, long long n) {
    long long ans = 1ll;
    while (n > 0) {
        if (n & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        n >>= 1ll;
    }
    return ans;
}
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    long long cnt = modpow(B, C);
    long long ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans *= A;
        ans %= 10;
    }
    cout << ans << endl;
}
