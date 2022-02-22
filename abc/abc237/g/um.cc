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
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 1 << 18;
struct Node {
	int l, r;
	int val;
	int setTo;

	Node() : l(), r(), val(0), setTo(-1) {}
	Node(int _l, int _r) : l(_l), r(_r), val(0), setTo(-1) {}

	void set(int x) {
		setTo = x;
		val = x * (r - l);
	}
};
Node tree[2 * N + 5];
void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void push(int v) {
	assert(v < N);
	if (tree[v].setTo == -1) return;
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[u].set(tree[v].setTo);
	}
	tree[v].setTo = -1;
}
void update(int v) {
	tree[v].val = tree[2 * v].val + tree[2 * v + 1].val;
}

void setOnSegm(int v, int l, int r, int x) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].set(x);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		setOnSegm(u, l, r, x);
	update(v);
}
int getSum(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return 0;
	push(v);
	return getSum(2 * v, l, r) + getSum(2 * v + 1, l, r);
}

const int M = 200200;
int n, q;
int a[N];
int Q[N][3];
int X;
int b[2][N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &q, &X);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &Q[i][0], &Q[i][1], &Q[i][2]);
		Q[i][1]--;
	}
	for (int k = 0; k < 2; k++) {
		build();
		for (int i = 0; i < n; i++)
			if (a[i] > X - k)
				setOnSegm(1, i, i + 1, 1);
		for (int i = 0; i < q; i++) {
			int x = getSum(1, Q[i][1], Q[i][2]);
			eprintf("x = %d\n", x);
			if (Q[i][0] == 1) {
				setOnSegm(1, Q[i][1], Q[i][2] - x, 0);
				setOnSegm(1, Q[i][2] - x, Q[i][2], 1);
			} else {
				setOnSegm(1, Q[i][1], Q[i][1] + x, 1);
				setOnSegm(1, Q[i][1] + x, Q[i][2], 0);
			}
		}
		for (int i = 1; i < N; i++)
			push(i);
		for (int i = 0; i < n; i++) {
			b[k][i] = tree[N + i].val;
			eprintf("%d ", b[k][i]);
		}
		eprintf("\n");
	}
	for (int i = 0; i < n; i++)
		if (b[0][i] != b[1][i])
			printf("%d\n", i + 1);

	return 0;
}
