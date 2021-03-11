#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  double vmax = 0;
  for (ll i = 0; i < N; i++) {
    double mark = 0;
    for (ll j = 0; j < 5; j++) {
      double x; cin >> x;
      if (j == 4) mark += x * 110.0 / 900.0;
      else        mark += x;
    }
    vmax = max(vmax, mark);
  }
  cout << vmax << endl;

  return 0;
}

