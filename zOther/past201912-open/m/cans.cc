#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, M; cin >> N >> M;
  vector<double> w(N), mp(N), ow(M), omp(M);
  for (int i = 0; i < N; i++) cin >> w.at(i) >> mp.at(i);
  for (int i = 0; i < M; i++) cin >> ow.at(i) >> omp.at(i);
  double lo = 0;
  double hi = 1e5;
  while (hi - lo > 1e-7) {
    double mid = (lo + hi) / 2.0;
    vector<double> vec(N), ovec(M);
    for (int i = 0; i < N; i++) vec.at(i) = mp.at(i) - mid * w.at(i);
    for (int i = 0; i < M; i++) ovec.at(i) = omp.at(i) - mid * ow.at(i);
    sort(vec.begin(), vec.end(), greater<double>());
    sort(ovec.begin(), ovec.end(), greater<double>());
    double x = 0.0;
    for (int i = 0; i < 4; i++) x += vec.at(i);
    x += max(vec.at(4), ovec.at(0));
    if (x >= 0) lo = mid;
    else        hi = mid;
  }

  cout << hi << endl;
  return 0;
}

