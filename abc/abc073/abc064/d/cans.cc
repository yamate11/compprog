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
  string S; cin >> S;
  ll cmin = 0;
  ll cur = 0;
  for (ll i = 0; i < N; i++) {
    if (S.at(i) == '(') {
      cur++;
    }else {
      cur--;
      updMin(cmin, cur);
    }
  }
  if (cmin < 0) cur -= cmin;
  for (ll i = 0; i < -cmin; i++) cout << '(';
  cout << S;
  for (ll i = cur; i > 0; i--) cout << ')';
  cout << endl;

  return 0;
}

