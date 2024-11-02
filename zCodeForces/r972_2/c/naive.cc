//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define mp make_pair
#define all(x) (x).begin(),(x).end()

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

ll floor_div(ll x, ll y) {
	assert(y != 0);
	if (y < 0) {
		y = -y;
		x = -x;
	}
	if (x >= 0) return x / y;
	return (x + 1) / y - 1;
}
ll ceil_div(ll x, ll y) {
	assert(y != 0);
	if (y < 0) {
		y = -y;
		x = -x;
	}
	if (x <= 0) return x / y;
	return (x - 1) / y + 1;
}
template<typename T>
T sqr(T x) {
	return x * x;
}

const int INF = (int)1e8;
const int K = 5;
const int N = 1010;
char b[] = "narek";
char a[N][N];
int n, m;
int dp[2][K];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);
	for (int k = 0; k < K; k++)
		dp[0][k] = -INF;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int cost = 0;
		for (int j = 0; j < m; j++)
			for (int k = 0; k < K; k++)
				cost += (int)(b[k] == a[i][j]);
		for (int k = 0; k < K; k++)
			dp[1][k] = dp[0][k];
		for (int k = 0; k < K; k++) {
			int cur = dp[0][k] - cost;
			int p = k;
			for (int j = 0; j < m; j++) {
				if (a[i][j] == b[p]) {
					p++;
					if (p == K) {
						p = 0;
						cur += 2 * K;
					}
				}
			}
			dp[1][p] = max(dp[1][p], cur);
		}
		for (int k = 0; k < K; k++)
			dp[0][k] = dp[1][k];
	}
	int ans = 0;
	for (int k = 0; k < K; k++)
		ans = max(ans, dp[0][k]);
	printf("%d\n", ans);
}

int main() {
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		eprintf("--- Case #%d start ---\n", i);
		//printf("Case #%d: ", i);

		solve();

		//printf("%lld\n", (ll)solve());

		/*
		if (solve()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
		*/

		eprintf("--- Case #%d end ---\n", i);
		eprintf("time = %.5lf\n", getCurrentTime());
		eprintf("++++++++++++++++++++\n");
	}


	return 0;
}
