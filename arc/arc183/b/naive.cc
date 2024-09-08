#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n_tests;
	cin >> n_tests;
	for (int test = 0; test < n_tests; test++) {
		int k, n;
		cin >> n >> k;
		vector<int> a(n), b(n);
		for (int&x:a) cin >> x, x--;
		for (int&x:b) cin >> x, x--;
		bool ans;
		if (k == 1) {
			b.erase(begin(ranges::unique(b)), end(b));
			auto it = begin(b);
			for (int x: a) {
				if (it == end(b)) break;
				if (x == *it) ++it;
			}
			ans = it == end(b);
		} else if (a == b) {
			ans = true;
		} else {
			ans = false;
			vector<int> s(n);
			for (int i = 0; i < n; i++) {
				ans |= (bool) s[b[i]];
				s[b[i]]++;
				if (i >= k) s[b[i-k]]--;
			}
			ranges::fill(s, 0);
			for (int x: a) s[x] = 1;
			for (int x: b) ans &= (bool) s[x];
		}
		cout << (ans ? "Yes\n" : "No\n");
	}
}
