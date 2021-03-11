#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

using Pair = pair<double, double>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  vector<double> X(N), R(N), H(N), A(Q), B(Q);
  for (int i = 0; i < N; i++) cin >> X.at(i) >> R.at(i) >> H.at(i);

  auto funcRH = [&](int i, double x) -> Pair {
    double xr = X.at(i) + H.at(i);
    if (x <= X.at(i)) return {R.at(i), H.at(i)};
    if (xr <= x) return {0, 0};
    return {(xr - x) * R.at(i) / H.at(i), xr - x};
  };

  for (int j = 0; j < Q; j++) {
    double a, b; cin >> a >> b;
    double vol = 0;
    for (int i = 0; i < N; i++) {
      double ra, rb, ha, hb;
      tie(ra, ha) = funcRH(i, a);
      tie(rb, hb) = funcRH(i, b);
      vol += (M_PI / 3.0) * (ra * ra * ha  - rb * rb * hb);
    }
    cout << vol << "\n";
  }

  return 0;
}

