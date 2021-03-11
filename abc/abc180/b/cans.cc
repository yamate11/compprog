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

  ll N; cin >> N;
  vector<double> X(N);
  double m = 0.0;
  double e = 0.0;
  double t = 0.0;
  for (ll i = 0; i < N; i++) {
    double x; cin >> x;
    m += abs(x);
    e += x * x;
    t = max(t, abs(x));
  }
  e = sqrt(e);
  cout << m << endl;
  cout << e << endl;
  cout << t << endl;

  return 0;
}

