#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppi;

int n, q, X;
int a[200010];
int C[200010], L[200010], R[200010];
int f[200010], g[200010];
set <ppi> S;

void Solve(int Lim, int *f) {
	S.clear();
	for (int i = 1; i <= n; i++) {
		S.insert(mp(mp(i, i), a[i] > Lim));
	}
	for (int i = 0; i < q; i++) {
		int op = C[i], l = L[i], r = R[i];
		int c0 = 0, c1 = 0;
		auto it = S.lower_bound(mp(mp(l, -1), -1));
		vector <ppi> ins;
		int lst = l - 1;
		while (it != S.end() && it->fi.se <= r) {
			int ll = it->fi.se, rr = it->fi.fi, v = it->se;
			if (ll < l) ins.push_back(mp(mp(ll, l - 1), v)), ll = l;
			if (r < rr) ins.push_back(mp(mp(r + 1, rr), v)), rr = r;
			assert(lst + 1 == ll), lst = rr;
			if (v == 0) c0 += rr - ll + 1;
			else c1 += rr - ll + 1;
			it = S.erase(it);
		}
		if (op == 1) {
			ins.push_back(mp(mp(l, l + c0 - 1), 0));
			ins.push_back(mp(mp(l + c0, r), 1));
		} else {
			ins.push_back(mp(mp(l, l + c1 - 1), 1));
			ins.push_back(mp(mp(l + c1, r), 0));
		}
		for (auto it : ins) {
			swap(it.fi.fi, it.fi.se);
			S.insert(it);
		}
	}
	for (auto it : S) {
		int l = it.fi.se, r = it.fi.fi, v = it.se;
		for (int i = l; i <= r; i++) {
			f[i] = v;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &q, &X);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &C[i], &L[i], &R[i]);
	}
	Solve(X - 1, f), Solve(X, g);
	for (int i = 1; i <= n; i++) {
		if (f[i] && !g[i]) {
			printf("%d\n", i);
			return 0;
		}
	}
	assert(0);
	return 0;
}
