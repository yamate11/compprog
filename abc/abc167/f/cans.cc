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
  using Pair = pair<ll, ll>;
  vector<Pair> left, right;

  ll diffL = 0;
  ll diffR = 0;
  for (ll z = 0; z < N; z++) {
    string s; cin >> s;
    ll vmin = 0;
    ll acc = 0;
    for (ll i = 0; i < (ll)s.size(); i++) {
      if (s.at(i) == '(') acc++;
      else acc--;
      updMin(vmin, acc);
    }
    if (acc >= 0) {
      left.emplace_back(vmin, acc);
      diffL += acc;
    }else {
      right.emplace_back(vmin - acc, -acc);
      diffR -= acc;
    }
  }

  auto chk = [&](auto& vec) -> bool {
    sort(vec.begin(), vec.end(), greater<Pair>());
    ll cur = 0;
    for (auto& [vmin, acc] : vec) {
      if (cur + vmin < 0) return false;
      cur += acc;
    }
    return true;
  };
  if (diffL == diffR && chk(left) && chk(right)) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }
  

  return 0;
}

