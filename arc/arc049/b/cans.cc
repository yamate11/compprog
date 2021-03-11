#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> X(N), Y(N), C(N);
  for (int i = 0; i < N; i++) cin >> X.at(i) >> Y.at(i) >> C.at(i);
  auto calc = [&](auto Z) -> double {
    double ret = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++) {
	double v = 1.0 / (double)C.at(i) + 1.0 / (double)C.at(j);
	ret = max(ret, abs(Z.at(i) - Z.at(j)) / v);
      }
    }
    return ret;
  };

  double x = calc(X);
  double y = calc(Y);
  cout << max(x, y) << endl;

  return 0;
}

