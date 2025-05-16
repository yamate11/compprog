#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using std::cerr;
using std::cin;
using std::cout;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using mint = atcoder::modint1000000007;
istream &operator>>(istream &is, mint &a) {
	int t;
	is >> t;
	a = t;
	return is;
}
ostream &operator<<(ostream &os, mint a) { return os << a.val(); }
#endif
typedef long double ld;
#define long long long
#define uint unsigned int
#define ull unsigned long
#define overload3(a, b, c, name, ...) name
#define rep3(i, a, b) for (int i = (a); i < (b); i++)
#define rep2(i, n) rep3(i, 0, n)
#define rep1(n) rep2(i, n)
#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define per3(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define per2(i, n) per3(i, 0, n)
#define per1(n) per2(i, n)
#define per(...) overload3(__VA_ARGS__, per3, per2, per1)(__VA_ARGS__)
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a)                                                              \
	sort(ALL(a));                                                              \
	a.erase(unique(ALL(a)), a.end())
#define SZ(a) (int)a.size()
#define vec vector
#ifndef DEBUG
#define cerr                                                                   \
	if (0)                                                                     \
	cerr
// #undef assert
// #define assert(...) void(0)
#undef endl
#define endl '\n'
#endif
template <typename T> ostream &operator<<(ostream &os, vector<T> a) {
	const int n = a.size();
	rep(i, n) {
		os << a[i];
		if (i + 1 != n)
			os << " ";
	}
	return os;
}
template <typename T, size_t n>
ostream &operator<<(ostream &os, array<T, n> a) {
	rep(i, n) {
		os << a[i];
		if (i + 1 != n)
			os << " ";
	}
	return os;
}
template <typename T> istream &operator>>(istream &is, vector<T> &a) {
	for (T &i : a)
		is >> i;
	return is;
}
template <typename T, typename S> bool chmin(T &x, S y) {
	if ((T)y < x) {
		x = (T)y;
		return true;
	}
	return false;
}
template <typename T, typename S> bool chmax(T &x, S y) {
	if (x < (T)y) {
		x = (T)y;
		return true;
	}
	return false;
}
template <typename T> void operator++(vector<T> &a) {
	for (T &i : a)
		++i;
}
template <typename T> void operator--(vector<T> &a) {
	for (T &i : a)
		--i;
}
template <typename T> void operator++(vector<T> &a, int) {
	for (T &i : a)
		i++;
}
template <typename T> void operator--(vector<T> &a, int) {
	for (T &i : a)
		i--;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vec<vec<pair<int, long>>> g(n + 1);
	rep(i, n) g[i].emplace_back(i + 1, -1);
	rep(i, m) {
		int l, r;
		long s;
		cin >> l >> r >> s;
		l--;
		g[l].emplace_back(r, -s);
		g[r].emplace_back(l, s);
	}
	constexpr long inf = 1e18;
	vec<long> d(n + 1, inf);
	d[0] = 0;
	rep(looo, n + 1) rep(i, n + 1) for (auto [j, c] : g[i])
		chmin(d[j], d[i] + c);
	rep(i, n + 1) for (auto [j, c] : g[i]) if (chmin(d[j], d[i] + c)) {
		cout << -1 << endl;
		return;
	}
	cout << -d[n] << endl;
	return;
}
int main() {
	// srand((unsigned)time(NULL));
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
}
