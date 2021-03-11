#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  ll a = 0;
  ll b = s.size() - 1;
  while (a < b) {
    if (s.at(a) != '*' && s.at(b) != '*' && s.at(a) != s.at(b)) {
      cout << "NO" << endl;
      return 0;
    }
    a++;
    b--;
  }
  cout << "YES" << endl;

  return 0;
}

