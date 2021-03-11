#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;
  ll cnt = 0;
  ll i = 0;
  ll j = N-1;
  while (true) {
    while (i < j && S.at(i) == 'R') i++;
    while (i < j && S.at(j) == 'W') j--;
    if (i >= j) break;
    cnt++;
    i++;
    j--;
  }
  cout << cnt << endl;


  return 0;
}

