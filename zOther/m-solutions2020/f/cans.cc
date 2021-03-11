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
  vector<ll> X(N), Y(N);
  vector<char> U(N);
  map<ll, vector<ll>> mpX, mpY, mpP, mpM;
  ll crash = LLONG_MAX;
  for (ll i = 0; i < N; i++) {
    ll x, y; cin >> x >> y;
    char u; cin >> u;
    X.at(i) = x;
    Y.at(i) = y;
    U.at(i) = u;
    if (u == 'U' || u == 'D') mpX[x].push_back(i);
    if (u == 'L' || u == 'R') mpY[y].push_back(i);
    mpP[y + x].push_back(i);
    mpM[y - x].push_back(i);
  }
  for (auto [x, v] : mpX) {
    sort(v.begin(), v.end(),
	 [&](ll i, ll j) -> bool { return Y.at(i) < Y.at(j); });
    ll up = -1;
    for (ll i : v) {
      if (U.at(i) == 'U') {
	up = Y.at(i);
      }else {
	if (up >= 0) {
	  crash = min(crash, (Y.at(i) - up) * 5);
	}
      }
    }
  }
  for (auto [y, v] : mpY) {
    sort(v.begin(), v.end(),
	 [&](ll i, ll j) -> bool { return X.at(i) < X.at(j); });
    ll right = -1;
    for (ll i : v) {
      if (U.at(i) == 'R') {
	right = X.at(i);
      }else {
	if (right >= 0) {
	  crash = min(crash, (X.at(i) - right) * 5);
	}
      }
    }
  }
  for (auto [p, v] : mpP) {
    sort(v.begin(), v.end(),
	 [&](ll i, ll j) -> bool { return X.at(i) < X.at(j); });
    ll down = LLONG_MIN;
    ll right = LLONG_MIN;
    for (ll i : v) {
      if (U.at(i) == 'R') right = X.at(i);
      if (U.at(i) == 'D') down = X.at(i);
      if (U.at(i) == 'U' && right > LLONG_MIN) {
	crash = min(crash, (X.at(i) - right) * 10);
      }
      if (U.at(i) == 'L' && down > LLONG_MIN) {
	crash = min(crash, (X.at(i) - down) * 10);
      }
    }
  }
  for (auto [p, v] : mpM) {
    sort(v.begin(), v.end(),
	 [&](ll i, ll j) -> bool { return X.at(i) < X.at(j); });
    ll up = LLONG_MIN;
    ll right = LLONG_MIN;
    for (ll i : v) {
      if (U.at(i) == 'R') right = X.at(i);
      if (U.at(i) == 'U') up = X.at(i);
      if (U.at(i) == 'D' && right > LLONG_MIN) {
	crash = min(crash, (X.at(i) - right) * 10);
      }
      if (U.at(i) == 'L' && up > LLONG_MIN) {
	crash = min(crash, (X.at(i) - up) * 10);
      }
    }
  }

    
  if (crash == LLONG_MAX) {
    cout << "SAFE" << endl;
  }else {
    cout << crash << endl;
  }

  return 0;
}

