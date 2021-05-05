#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll R, C; cin >> R >> C;
  auto A = vector(R, vector(C-1, 0));
  auto B = vector(R - 1, vector(C, 0));
  for (ll i = 0; i < R; i++) {
    for (ll j = 0; j < C - 1; j++) cin >> A[i][j];
  }
  for (ll i = 0; i < R - 1; i++) {
    for (ll j = 0; j < C; j++) cin >> B[i][j];
  }
  ll big = 1e10;
  auto dist = vector(2, vector(R, vector(C, big)));
  using sta = tuple<ll, ll, ll, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  dist[0][0][0] = 0;
  pque.emplace(0, 0, 0, 0);
  while (!pque.empty()) {
    auto [d, z, r, c] = pque.top(); pque.pop();
    if (r == R - 1 && c == C - 1) {
      cout << d << endl;
      return 0;
    }
    if (dist[z][r][c] < d) continue;
    if (c + 1 < C) {
      ll newDist = d + A[r][c];
      if (newDist < dist[0][r][c + 1]) {
        dist[0][r][c + 1] = newDist;
        pque.emplace(newDist, 0, r, c + 1);
      }
    }
    if (c > 0) {
      ll newDist = d + A[r][c - 1];
      if (newDist < dist[0][r][c - 1]) {
        dist[0][r][c - 1] = newDist;
        pque.emplace(newDist, 0, r, c - 1);
      }
    }
    if (r + 1 < R) {
      ll newDist = d + B[r][c];
      if (newDist < dist[0][r + 1][c]) {
        dist[0][r + 1][c] = newDist;
        pque.emplace(newDist, 0, r + 1, c);
      }
    }
    if (r > 0) {
      ll newDist = (z == 0) ? d + 2 : d + 1;
      if (newDist < dist[1][r - 1][c]) {
        dist[1][r - 1][c] = newDist;
        pque.emplace(newDist, 1, r - 1, c);
      }
    }
  }

  return 0;
}

