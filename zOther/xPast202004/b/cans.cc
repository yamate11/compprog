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
  ll xa = 0;
  ll xb = 0;
  ll xc = 0;
  for (ll i = 0; i < (ll)S.size(); i++) {
    if (S.at(i) == 'a') xa++;
    else if (S.at(i) == 'b') xb++;
    else if (S.at(i) == 'c') xc++;
    else assert(0);
  }
  if (xa > xb && xa > xc) cout << "a" << endl;
  else if (xb > xa && xb > xc) cout << "b" << endl;
  else if (xc > xa && xc > xb) cout << "c" << endl;
  else assert(0);

  return 0;
}

