#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> vec(8);
  ll free = 0;
  ll N; cin >> N;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (a >= 3200) free++;
    else vec.at(a / 400) = 1;
  }
  ll cnt = 0;
  for (ll i = 0; i < 8; i++) { cnt += vec.at(i); }
  cout << max(cnt, 1LL) << " " << cnt + free << endl;

  return 0;
}

