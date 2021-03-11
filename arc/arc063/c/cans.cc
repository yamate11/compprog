#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll cnt = 0;
  for (ll i = 0; i < (ll)S.size()-1; i++) {
    if (S.at(i) != S.at(i+1)) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

