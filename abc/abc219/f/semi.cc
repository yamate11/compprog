#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

char S[202020];
i64 K;
int N;

pair<pair<i64, i64>, i64> canonize(i64 By, i64 Bx, i64 dy, i64 dx) {
	i64 g;
	if (dy >= 0) g = dy / By;
	else {
		g = -((-dy + By - 1) / By);
	}
	dy -= g * By;
	dx -= g * Bx;
	return {{dy, dx}, g};
}

int main()
{
	scanf("%s%lld", S, &K);
	N = strlen(S);

	int y = 0, x = 0;
	set<pair<int, int>> pts;
	pts.insert({0, 0});

	for (int i = 0; i < N; ++i) {
		if (S[i] == 'L') --x;
		else if (S[i] == 'R') ++x;
		else if (S[i] == 'U') --y;
		else if (S[i] == 'D') ++y;

		pts.insert({y, x});
	}

	if (y == 0 && x == 0) {
		printf("%d\n", (int)pts.size());
		return 0;
	}

	if (y == 0) {
		swap(y, x);
		set<pair<int, int>> pts2;
		for (auto& p : pts) pts2.insert({p.second, p.first});
		pts.swap(pts2);
	}
	if (y < 0) {
		y *= -1;
		set<pair<int, int>> pts2;
		for (auto& p : pts) pts2.insert({-p.first, p.second});
		pts.swap(pts2);
	}

	map<pair<i64, i64>, vector<i64>> grps;
	for (auto& p : pts) {
		auto chi = canonize(y, x, p.first, p.second);
		if (!(0 <= chi.first.first && chi.first.first < y)) return 0;
		grps[chi.first].push_back(chi.second);
	}

	i64 ret = 0;
	for (auto& p : grps) {
		sort(p.second.begin(), p.second.end());
		ret += K;
		for (int i = 1; i < p.second.size(); ++i) {
			ret += min(K, p.second[i] - p.second[i - 1]);
		}
	}
	printf("%lld\n", ret);
	
	return 0;
}
