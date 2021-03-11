#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch)
// --> binsearch
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector w(N, 0LL);
  vector p(N, 0.0);
  for (ll i = 0; i < N; i++) {
    cin >> w.at(i);
    ll q; cin >> q;
    p.at(i) = q / 100.0;
  }
  auto check = [&](double r) -> bool {
    vector<double> vec;
    for (ll i = 0; i < N; i++) {
      vec.push_back((p.at(i) - r) * w.at(i));
    }
    sort(vec.begin(), vec.end(), greater<double>());
    double s = 0.0;
    for (ll i = 0; i < K; i++) s += vec.at(i);
    return s >= 0;
  };
  double r = binsearch(check, 0.0, 100.0, 1e-8);
  cout << r * 100 << endl;
  

  return 0;
}

