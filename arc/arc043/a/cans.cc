#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  double A, B; cin >> A >> B;
  ll sMax = LLONG_MIN;
  ll sMin = LLONG_MAX;
  ll ssum = 0;
  for (ll i = 0; i < N; i++) {
    ll s; cin >> s;
    ssum += s;
    sMax = max(sMax, s);
    sMin = min(sMin, s);
  }
  if (sMax == sMin) {
    cout << -1 << endl;
    return 0;
  }
  double p = B / (sMax - sMin);
  double q = A - p * ssum / (double)N;
  cout << p << " " << q << endl;
  return 0;
}

