#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int inf = 1000000010;
template<class T, class U> inline bool chmax(T& a, const U& b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return true; } return false; }

int main() {
	int h, w;
	cin >> h >> w;
	vector a(h, vector<char>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	int px = -1, py = -1;
	rep(i, h) rep(j, w) if (a[i][j] == 'T') px = i, py = j;
	vector s(h + 1, vector<int>(w + 1));
	rep(i, h) rep(j, w) s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + (a[i][j] == '#');
	vector d(h + 1, vector(h + 1, vector(w + 1, vector(w + 1, vector(2 * h + 1, vector(2 * w + 1, inf))))));
	d[0][h][0][w][h][w] = 0;
	queue<array<int, 6>> que;
	que.push({ 0, h, 0, w, h, w });
	while (!que.empty()) {
		auto [lx, rx, ly, ry, xx, yy] = que.front(); que.pop(); // 元々の [lx, rx) x [ly, ry) が生き残っている、ずれが (xx - h, yy - w)
		if (s[rx][ry] + s[lx][ly] - s[lx][ry] - s[rx][ly] == 0) {
			cout << d[lx][rx][ly][ry][xx][yy] << '\n';
			return 0;
		}
		rep(D, 4) {
			int nlx = lx, nrx = rx, nly = ly, nry = ry, nxx = xx, nyy = yy;
			if (D == 0) nxx++;
			else if (D == 1) nxx--;
			else if (D == 2) nyy++;
			else nyy--;
			chmax(nlx, nxx - h); chmin(nrx, nxx); chmax(nly, nyy - w); chmin(nry, nyy);
			if (nxx > 2 * h or nxx < 0 or nyy > 2 * w or nyy < 0) continue;
			int X = px + nxx - h, Y = py + nyy - w;
			if (!(nlx <= X && X < nrx && nly <= Y && Y < nry && a[X][Y] == '#')) {
				if (d[nlx][nrx][nly][nry][nxx][nyy] == inf) {
					d[nlx][nrx][nly][nry][nxx][nyy] = d[lx][rx][ly][ry][xx][yy] + 1;
					que.push({ nlx, nrx, nly, nry, nxx, nyy });
				}
			}
		}
	}
	cout << -1 << '\n';
}
