#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <array>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_set>
#include <unordered_map>
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define req(i, a, b) for (ll i = (a); i < (b); i++)
#define pb push_back
#define debug(x) cerr << __LINE__ << ' ' << #x << ':' << (x) << '\n'
#define debug2(x, y) cerr << __LINE__ << ' ' << #x << ':' << (x) << ',' << #y << ':' << (y) << '\n'
#define debug3(x, y, z) cerr << __LINE__ << ' ' << #x << ':' << (x) << ',' << #y << ':' << (y) << ',' << #z << ':' << (z) << '\n'
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
template<class T> using P = pair<T, T>;
template<class T> using pri_s = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pri_b = priority_queue<T>;
constexpr int inf = 1000000010;
constexpr int inf2 = 2000000010;
constexpr ll INF = 1000000000000000010;
constexpr ll INF4 = 4000000000000000010;
constexpr int mod1e9 = 1000000007;
constexpr int mod998 = 998244353;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
constexpr ll ten(int n) { return n ? 10 * ten(n - 1) : 1; };
int dx[] = { 1,0,-1,0,1,1,-1,-1,0 }; int dy[] = { 0,1,0,-1,1,-1,1,-1,0 };
ll mul(ll a, ll b) { return (b != 0 && a > INF / b ? INF : a * b); }
void fail() { cout << "-1\n"; exit(0); } void no() { cout << "No\n"; exit(0); }
template<class T> void er(T a) { cout << a << '\n'; exit(0); }
template<class T, class U> inline bool chmax(T& a, const U& b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return true; } return false; }
template<class T> istream& operator >>(istream& s, vector<T>& v) { for (auto& e : v) s >> e; return s; }
template<class T> ostream& operator <<(ostream& s, const vector<T>& v) { for (auto& e : v) s << e << ' '; return s; }
template<class T, class U> ostream& operator << (ostream& s, const pair<T, U>& p) { s << p.first << ' ' << p.second; return s; }

struct fastio {
	fastio() {
		cin.tie(0); cout.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(20);
		cerr << fixed << setprecision(20);
	}
}fastio_;

namespace rdv {
	random_device seed_gen;
	mt19937_64 engine(seed_gen());
	ll rnum(ll r) { return engine() % r; } // [0, r)
	ll rnum(ll l, ll r) { return rnum(r - l) + l; } // [l, r)
	ll rng(ll l, ll r) { return rnum(l, r + 1); } // [l, r]
	double rng01() { return engine() * pow(2, -64); }
	template<class T> void shuf(vector<T>& v) { shuffle(all(v), engine); }
	void shuf(string& s) { shuffle(all(s), engine); }
}

using namespace rdv;

constexpr ll mod = mod998;
template <int mod> class modint {
public:
	int n;
	modint() : n(0) {};
	modint(ll n_) {
		n = n_ % mod;
		if (n < 0) n += mod;
	}
	modint operator -() const { return n > 0 ? mod - n : -n; }
	bool operator == (const modint& m) const { return n == m.n; }
	bool operator != (const modint& m) const { return n != m.n; }
	modint& operator += (const modint& m) { n += m.n; if (n >= mod) n -= mod; return *this; }
	modint& operator -= (const modint& m) { n -= m.n; if (n < 0) n += mod; return *this; }
	modint& operator *= (const modint& m) { n = ll(n) * m.n % mod; return *this; }
	modint& operator /= (const modint& m) { n = ll(n) * modinv(m).n % mod; return *this; }
	modint operator +(modint m) const { return modint(*this) += m; }
	modint operator -(modint m) const { return modint(*this) -= m; }
	modint operator *(modint m) const { return modint(*this) *= m; }
	modint operator /(modint m) const { return modint(*this) /= m; }
	modint& operator ++ () { *this += 1; return *this; }
	modint operator ++ (int) { *this += 1; return *this - 1; }
	modint& operator -- () { *this -= 1; return *this; }
	modint operator -- (int) { *this -= 1; return *this + 1; }
	modint pow(ll b) const {
		modint res = 1, a = modint(*this);
		while (b) {
			if (b & 1) res *= a;
			a *= a;
			b >>= 1;
		}
		return res;
	}
	friend istream& operator >> (istream& s, modint<mod>& a) { s >> a.n; return s; }
	friend ostream& operator << (ostream& s, modint<mod>& a) { s << a.n; return s; }
};

using mint = modint<mod>;

mint modinv(mint x) {
	ll a = x.n;
	if (a == 0) abort();
	ll b = mod, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	mint res = u;
	return res;
}

vector<mint> fac, inv, facinv;

void modcalc(int n) {
	fac.resize(n); inv.resize(n); facinv.resize(n);
	fac[0] = 1; fac[1] = 1; inv[1] = 1;
	facinv[0] = 1; facinv[1] = 1;
	for (ll i = 2; i < n; i++) {
		fac[i] = fac[i - 1] * i;
		inv[i] = -inv[mod % i] * (mod / i);
		facinv[i] = facinv[i - 1] * inv[i];
	}
}

mint comb(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[k] * facinv[n - k];
}

mint perm(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[n - k];
}

mint hom(ll n, ll k) {
	if (n < 0 || k < 0 || n == 0 && k > 0) return 0;
	if (n == 0 && k == 0) return 1;
	return fac[n + k - 1] * facinv[k] * facinv[n - 1];
}

int main() {
	int n;
	cin >> n;
	vector<int> c(2 * n);
	rep(i, n) {
		cin >> c[i];
		c[i]--;
		c[n + i] = c[i];
	}
	vector<int> x(n);
	cin >> x;
	vector dp(2 * n + 1, vector(2 * n + 1, INF)); // 全部 0 にする cost
	vector ep(2 * n + 1, vector(2 * n + 1, INF)); // 全部 0 or c[l] にする cost
	rep(i, 2 * n + 1) {
		dp[i][i] = 0;
		ep[i][i] = 0;
	}
	for (int l = 2 * n; l >= 0; l--) {
		for (int r = l + 1; r <= 2 * n; r++) {
			// [l, r)
			for (int m = l + 1; m < r; m++) {
				chmin(dp[l][r], dp[l][m] + dp[m][r]);
				chmin(ep[l][r], ep[l][m] + dp[m][r]);
			}
			if (c[l] == c[r - 1]) {
				chmin(ep[l][r], ep[l][r - 1]);
				int col = c[l];
				ll cost = r - l + x[col];
				chmin(dp[l][r], ep[l][r] + cost);
			}
			chmin(ep[l][r], dp[l][r]);
		}
	}
	ll ans = INF;
	rep(i, n) chmin(ans, dp[i][n + i]);
	cout << ans << '\n';
}
