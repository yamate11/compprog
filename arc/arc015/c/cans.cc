#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:updMaxMin)
// --> f:updMaxMin
// ---- inserted function updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end updMaxMin
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  map<string, vector<pair<string, double>>> mp;
  for (ll i = 0; i < N; i++) {
    string s1, s2; ll d; cin >> s1 >> d >> s2;
    mp[s1].emplace_back(s2, 1.0/(double)d);
    mp[s2].emplace_back(s1, d);
  }
  map<string, double> meas;
  queue<pair<string, double>> que;
  que.emplace(mp.begin()->first, 1e9);
  while (!que.empty()) {
    auto p = que.front(); que.pop();
    if (meas.find(p.first) != meas.end()) continue;
    meas[p.first] = p.second;
    for (auto u : mp[p.first]) {
      if (meas.find(u.first) != meas.end()) continue;
      que.emplace(u.first, u.second * p.second);
    }
  }
  double vMax = 0;
  string sMax;
  double vMin = 1e18;
  string sMin;
  for (auto p : meas) {
    if (updMax(vMax, p.second)) sMax = p.first;
    if (updMin(vMin, p.second)) sMin = p.first;
  }
  cout << "1" << sMax << "=" << (ll)(floor((vMax / vMin) + 0.5)) << sMin << endl;

  return 0;
}

