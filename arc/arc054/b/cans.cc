#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double P; cin >> P;
  double x = log(2.0 / 3.0 * P * log(2.0)) / log(2.0) / 2 * 3;
  double t;
  if (x <= 0) t = P;
  else t = x + P * exp((- log(2.0)) * 2.0 / 3.0 * x);
  cout << t << endl;

  return 0;
}

