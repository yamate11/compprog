#include <bits/stdc++.h>

//#include <atcoder/all>
#define For(i, a, b) for (int(i) = (int)(a); (i) < (int)(b); ++(i))
#define rFor(i, a, b) for (int(i) = (int)(a)-1; (i) >= (int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T div_floor(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a >= 0 ? a / b : (a + 1) / b - 1;
}
template <class T>
T div_ceil(T a, T b) {
    if (b < 0) a *= -1, b *= -1;
    return a > 0 ? (a - 1) / b + 1 : a / b;
}

constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 100010;

int n, m, K;
bool ng[MAX];

bool check(double mid) {
    long double dp[n + 1], dpsum[n + 2];
    dp[n] = dpsum[n + 1] = 0;
    dpsum[0] = 0;
    rrep(i, n) {
        if (ng[i])
            dp[i] = mid;
        else
            dp[i] = 1 + (dpsum[i + 1] - dpsum[min(i + m + 1, n + 1)]) / m;
        dpsum[i] = dpsum[i + 1] + dp[i];
    }
    return dp[0] <= mid;
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    rep(i, K) {
        int a;
        scanf("%d", &a);
        ng[a] = true;
    }
    {
        for (int l = 0; l < n + 1;) {
            if (!ng[l]) {
                ++l;
                continue;
            }
            int r = l;
            while (r < n + 1 && ng[r]) ++r;
            if (r - l >= m) {
                puts("-1");
                return 0;
            }
            l = r;
        }
    }

    double low = -1, high = INF;
    cerr << setprecision(20);
    while (true) {
      double mid = (high + low) / 2;
      // if (high - mid < 1e-4 || high - mid < 1e-4 * mid) break;
      if (high - mid < 1e-4) break;
      cerr << mid << endl;
      (check(mid) ? high : low) = mid;
    }
    printf("%.10lf\n", high);
}
