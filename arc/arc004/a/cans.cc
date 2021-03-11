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
  double dmax = 0;
  vector<double> X(N), Y(N);
  for (ll i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
  }
  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      dmax = max(dmax, hypot(X.at(i) - X.at(j), Y.at(i) - Y.at(j)));
    }
  }
  cout << dmax << endl;

  return 0;
}

