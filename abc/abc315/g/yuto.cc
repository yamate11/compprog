#include<bits/stdc++.h>

using namespace std;

using ll = long long;

// return gcd(a, b)
// solve  ax + by = gcd(a, b)
// |x| <= b, |y| <= a (if a*b != 0)
ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// composite_mod
// gcd(a, mod) must be 1
ll mod_inverse(ll a, ll mod) {
    ll x, y;
    ext_gcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

int main() {
    ll n, a, b, c, x;
    cin >> n >> a >> b >> c >> x;
    ll g = gcd(b, c);
    b /= g, c /= g;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        x -= a;
        if (x <= 0) break;
        if (x % g) continue;
        ll nx = x / g;
        ll j = mod_inverse(b, c) * (nx % c) % c;
        if (!j) j = c;
        if (j > n) continue;
        if (nx < b * j + c) continue;
        // 1 <= j + yc <= n && 1 <= (nx - bj) / c - by <= n
        ll mn = max(0LL, ((nx - b * j) / c - n + b - 1) / b);
        ll mx = min((n - j) / c, ((nx - b * j) / c - 1) / b);
        ans += max(0LL, mx - mn + 1);
    }
    cout << ans << endl;
}
