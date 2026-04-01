#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using std::cerr, std::cin, std::cout;
#define vec vector
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using mint = atcoder::modint998244353;
std::istream &operator>>(std::istream &is, mint &a) {
	long long t;
	is >> t;
	a = t;
	return is;
}
std::ostream &operator<<(std::ostream &os, mint a) { return os << a.val(); }
// vec<mint> operator*(const vec<mint> &a, const vec<mint> &b) { return a.empty() || b.empty() ? vec<mint>() : atcoder::convolution(a, b); }
// vec<mint> &operator*=(vec<mint> &a, const vec<mint> &b) { return a = a * b; }
#endif
typedef long double ld;
#if LONG_MAX == 2147483647L
#undef long
#define long long long
#endif
#define uint unsigned int
#define ulong unsigned long
#define overload3(a, b, c, name, ...) name
#define rep3(i, a, b) for (int i = (a); i < (b); i++)
#define rep2(i, n) rep3(i, 0, n)
#define rep1(n) rep2(__i, n)
#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define per3(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define per2(i, n) per3(i, 0, n)
#define per1(n) per2(__i, n)
#define per(...) overload3(__VA_ARGS__, per3, per2, per1)(__VA_ARGS__)
#define all(a) a.begin(), a.end()
#define UNIQUE(a) sort(all(a)), a.erase(unique(all(a)), a.end()), a.shrink_to_fit()
#define sz(a) static_cast<int>(a.size())
#ifndef DEBUG
#define cerr \
	if (false) cerr
// #undef assert
// #define assert(...) void(0)
#undef endl
#define endl '\n'
#endif
ostream &operator<<(ostream &os, __int128_t value) {
	ostream::sentry s(os);
	if (s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while (tmp != 0);
		if (value < 0) --d, *d = '-';
		const int len = std::end(buffer) - d;
		if (os.rdbuf()->sputn(d, len) != len) os.setstate(std::ios_base::badbit);
	}
	return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> a) {
	return os << a.first << ' ' << a.second;
};
template <typename T>
ostream &operator<<(ostream &os, vector<T> a) {
	const int n = a.size();
	rep(i, n) {
		os << a[i];
		if (i + 1 != n) os << " ";
	}
	return os;
}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &a) {
	return is >> a.first >> a.second;
}
template <typename T, size_t n>
ostream &operator<<(ostream &os, array<T, n> a) {
	rep(i, n) {
		os << a[i];
		if (i + 1 != n) os << " ";
	}
	return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &a) {
	for (T &i : a) is >> i;
	return is;
}
template <typename T, typename S>
bool chmin(T &x, S y) {
	if ((T)y < x) {
		x = (T)y;
		return true;
	}
	return false;
}
template <typename T, typename S>
bool chmax(T &x, S y) {
	if (x < (T)y) {
		x = (T)y;
		return true;
	}
	return false;
}
template <typename T>
void operator++(vector<T> &a) {
	for (T &i : a) ++i;
}
template <typename T>
void operator--(vector<T> &a) {
	for (T &i : a) --i;
}
template <typename T>
void operator++(vector<T> &a, int) {
	for (T &i : a) i++;
}
template <typename T>
void operator--(vector<T> &a, int) {
	for (T &i : a) i--;
}
void solve();
int main() {
	// srand((unsigned)time(NULL));
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
void solve() {
	string x, y;
	cin >> x >> y;
	const int n = sz(x), m = sz(y);
	vec<vec<long>> xx(n, vec<long>(26));
	vec<vec<long>> yy(m, vec<long>(26));
	rep(i, n) xx[i][x[i] - 'a']++;
	rep(i, m) yy[i][y[i] - 'a']++;
	rep(i, 1, n) rep(j, 26) xx[i][j] += xx[i - 1][j];
	rep(i, 1, m) rep(j, 26) yy[i][j] += yy[i - 1][j];
	vec<long> a = {n, m};
	vec<vec<long>> b = {xx[n - 1], yy[m - 1]};
	constexpr long INF = 1e18;
	while (a.back() < INF) {
		a.push_back(a[sz(a) - 1] + a[sz(a) - 2]);
		vec<long> bb(26);
		rep(j, 26) bb[j] = b[sz(b) - 1][j] + b[sz(b) - 2][j];
		b.push_back(bb);
	}
	auto f = [&](auto f, int idx, long r, int c) -> long {
		if (r < 0) return 0;
		if (idx == 0) return xx[r][c];
		if (idx == 1) return yy[r][c];
		if (r < a[idx - 1]) return f(f, idx - 1, r, c);
		return f(f, idx - 2, r - a[idx - 1], c) + b[idx - 1][c];
	};
	int que;
	cin >> que;
	while (que--) {
		long l, r;
		char c;
		cin >> l >> r >> c;
		l--, r--;
		cout << f(f, sz(a) - 1, r, c - 'a') - f(f, sz(a) - 1, l - 1, c - 'a') << endl;
	}
}
