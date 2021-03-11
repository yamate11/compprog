#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int solve() {
  ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
  if (C == 0 && D == 0) return A == B;
  ll M = N - 1;
  double diff = abs(B - A);
  double big = D;
  double small = C;
  double mid = (big + small) / 2;
  double h = (big - small) / 2;
  ll x = 0;
  if (diff >= M*mid) x = M;
  else {
    if (M % 2 == 0) {
      x = 2 * (ll)floor(0.5 + diff / (2*mid));
    }else {
      x = -1 + 2 * (ll)floor(0.5 + (diff + mid) / (2*mid));
    }
  }
  assert(x <= M);
  if (x * mid - M*h <= diff && diff <= x * mid + M*h) return 1;
  return 0;
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  if (solve()) {
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }

  return 0;
}

