#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  string s; cin >> s;
  ll sz = s.size();
  ll p = 0;
  while (s[p] != 'G') p++;
  ll p0 = p;
  for (; p < sz; p += k) {
    if (s[p] == '#') break;
    if (s[p] == 'T') {
      cout << "YES\n";
      return 0;
    }
  }
  for (p = p0; p >= 0; p -= k) {
    if (s[p] == '#') break;
    if (s[p] == 'T') {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";



  return 0;
}

