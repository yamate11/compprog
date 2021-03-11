#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> cnt(7);
  for (ll i = 0; i < N; i++) {
    double M, m; cin >> M >> m;
    if (M >= 34.999) cnt.at(1)++;
    if (29.999 <= M && M < 34.999) cnt.at(2)++;
    if (24.999 <= M && M < 29.999) cnt.at(3)++;
    if (m >= 24.999) cnt.at(4)++;
    if (m < -0.001 && M >= -0.001) cnt.at(5)++;
    if (M < -0.001) cnt.at(6)++;
  }
  for (ll i = 1; i <= 6; i++) {
    if (i > 1) cout << " ";
    cout << cnt.at(i);
  }
  cout << endl;

  return 0;
}

