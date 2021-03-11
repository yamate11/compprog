#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll lim = 1e6;
  ll N; cin >> N;
  vector<char> vec(lim + 1);
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    vec.at(a) += 1;
  }
  ll cnt = 0;
  for (ll i = 1; i <= lim; i++) {
    if (vec.at(i) == 0) continue;
    if (vec.at(i) == 1) cnt++;
    for (ll t = i * 2; t <= lim; t += i) vec.at(t) = 0;
  }
  cout << cnt << endl;

  return 0;
}

