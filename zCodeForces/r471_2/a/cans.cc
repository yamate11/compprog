#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll hh, mm; cin >> hh >> mm;
  ll H, D, C, N; cin >> H >> D >> C >> N;

  ll n_now = (H + N - 1) / N;
  double cost;
  if (hh >= 20) {
    cost = n_now * C * 0.8;
  }else {
    double cost_now = n_now * C;
    ll dur_8 = 20 * 60 - (hh * 60 + mm);
    ll H_8 = H + dur_8 * D;
    ll n_8 = (H_8 + N - 1) / N;
    double cost_8 = n_8 * C * 0.8;
    cost = min(cost_now, cost_8);
  }
  cout << cost << endl;

  return 0;
}

