#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  ll N; cin >> N;
  vector<string> S(N);
  for (ll i = 0; i < N; i++) cin >> S.at(i);
  ll cnt = 0;
  ll j = N-1;
  for (ll i = 0; i < N; i++) {
    for ( ; j >= 0 && S.at(i).at(j) == 'o'; j--) ;
    if (j < 0) {
      j = N-1;
      continue;
    }
    cnt ++;
    j--;
  }
  cout << cnt << endl;
  return 0;
}

