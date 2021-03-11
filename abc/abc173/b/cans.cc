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
  ll ac = 0;
  ll wa = 0;
  ll tle = 0;
  ll re = 0;
  for (ll i = 0; i < N; i++) {
    string S; cin >> S;
    if (S == "AC") {
      ac++;
    }else if (S == "WA") {
      wa++;
    }else if (S == "TLE") {
      tle++;
    }else if (S == "RE") {
      re++;
    }
  }
  cout << "AC x " << ac << endl;
  cout << "WA x " << wa << endl;
  cout << "TLE x " << tle << endl;
  cout << "RE x " << re << endl;

  return 0;
}

