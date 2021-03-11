#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  ll n = s.size();
  if (s[n-1] == 's') {
    cout << s << "es" << endl;
  }else {
    cout << s << "s" << endl;
  }

  return 0;
}

