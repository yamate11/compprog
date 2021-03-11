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
  vector<ll> cnt(4);
  for (ll i = 0; i < N; i++) {
    char a; cin >> a; a--;
    cnt.at(a - '0')++;
  }
  sort(cnt.begin(), cnt.end());
  cout << cnt.at(3) << " " << cnt.at(0) << endl;

  return 0;
}

