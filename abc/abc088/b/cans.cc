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
  vector<ll> a(N);
  for (ll i = 0; i < N; i++) cin >> a.at(i);
  sort(a.begin(), a.end(), greater<ll>());
  ll A = 0; ll B = 0;
  for (ll i = 0; i < N; i++) {
    if (i % 2 == 0) A += a.at(i);
    else B += a.at(i);
  }
  cout << A - B << endl;

  return 0;
}

