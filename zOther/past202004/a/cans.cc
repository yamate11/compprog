#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll dec(string s) {
  if (s.at(0) == 'B') return 1 - (s.at(1) - '0');
  else return s.at(0) - '0';
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S, T; cin >> S >> T;
  ll x = dec(S);
  ll y = dec(T);
  cout << abs(x-y) << endl;

  return 0;
}

