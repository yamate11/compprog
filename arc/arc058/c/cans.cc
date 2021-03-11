#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector<bool> vec(10);
  for (ll i = 0; i < K; i++) {
    ll d; cin >> d;
    vec.at(d) = true;
  }

  auto sat = [&](ll x) -> bool {
    if (x == 0) return !vec.at(0);
    for ( ; x > 0; x /= 10) {
      if (vec.at(x % 10)) return false;
    }
    return true;
  };
  ll n = N;
  while (true) {
    if (sat(n)) {
      cout << n << endl;
      return 0;
    }
    n++;
  }

  return 0;
}

