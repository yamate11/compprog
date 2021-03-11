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
  ll cnt = 0;
  auto check = [&](string name) -> ll {
    ll a = 0;
    for (ll i = 0; i < (ll)s.size(); i++) {
      if (s.substr(i, name.size()) == name) a++;
    }
    return a;
  };

  cnt += check("Danil");
  cnt += check("Olya");
  cnt += check("Slava");
  cnt += check("Ann");
  cnt += check("Nikita");
  if (cnt == 1) {
    cout << "YES\n";
  }else {
    cout << "NO\n";
  }
  
   

  return 0;
}

