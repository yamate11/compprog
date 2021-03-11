#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

bool solve(double A, double B, double C, double D) {
  if (B > D) return false;
  if (A <= C) return true;
  if (A*A >= C*C + D*D) return false;

  auto y2sl = [&](double y, double& s, double& l) -> void {
    double x = C/2 - sqrt((D/2 - y) * (D/2 - y) + C*C/4 - D*D/4);
    s = sqrt(x*x + y*y);
    l = sqrt((C - x) * (C - x) + (D - y) * (D - y));
  };

  double s, l; y2sl(D/2, s, l);
  if (B > s) return false;
  double yL = 0, yH = D / 2;
  while (true) {
    double y = (yL + yH) / 2;
    y2sl(y, s, l);
    if (B <= s && A <= l) return true;
    if (B > s && A > l) return false;
    if (B < s) yH = y;
    else       yL = y;
  }
}
    

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double A, B; cin >> A >> B;
  if (A < B) swap(A, B);
  ll N; cin >> N;
  for (ll i = 0; i < N; i++) {
    double C, D; cin >> C >> D;
    if (C < D) swap(C, D);
    cout << (solve(A, B, C, D) ? "YES\n" : "NO\n");
  }
  return 0;
}

