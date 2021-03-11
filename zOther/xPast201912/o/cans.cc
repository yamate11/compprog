#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

using Tuple = tuple<ll, ll, ll>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<vector<ll>> A;
  vector<Tuple> surface;
  for (int i = 0; i < N; i++) {
    vector<ll> x(6);
    for (int j = 0; j < 6; j++) {
      cin >> x.at(j);
      surface.emplace_back(x.at(j), i, j);
    }
    sort(x.begin(), x.end(), greater<ll>());
    A.push_back(move(x));
  }
  sort(surface.begin(), surface.end(), greater<Tuple>());
  vector<double> exp(N, 0.0);
  double eMax = 0.0;
  for (Tuple surf : surface) {
    ll x, i, j; tie(x, i, j) = surf;
    exp.at(i) += (1.0 + eMax) / 6.0;
    eMax = max(eMax, exp.at(i));
  }
  cout << 1.0 + eMax << endl;

  return 0;
}

