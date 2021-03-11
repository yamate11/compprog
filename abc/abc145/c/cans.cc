#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<double> x(N), y(N);
  for (int i = 0; i < N; i++) cin >> x.at(i) >> y.at(i);
  double t = 0.0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      double xd = x.at(i) - x.at(j);
      double yd = y.at(i) - y.at(j);
      double d = sqrt(xd*xd + yd*yd);
      t += d;
    }
  }
  cout << t * 2 / N << endl;

  return 0;
}

