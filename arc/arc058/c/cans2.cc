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

  auto suit = [&](const auto& recF, ll x) -> ll {
    if (x < 10) {
      ll i = x;
      for ( ; i < 10 && vec.at(i); i++);
      if (i < 10) return i;
      for (i = 1; vec.at(i); i++);
      return i * 10 + (vec.at(0) ? i : 0);
    }
    ll y = recF(recF, x / 10);
    if (y > x / 10) return y * 10 + recF(recF, 0);
    ll z = recF(recF, x % 10);
    if (z < 10) return y * 10 + z;
    y = recF(recF, 1 + x / 10);
    return y * 10 + recF(recF, 0);
  };
  cout << suit(suit, N) << endl;

  return 0;
}

