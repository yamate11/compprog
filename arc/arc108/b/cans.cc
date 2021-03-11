#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string s; cin >> s;
  vector<char> v;
  ll p = 0;
  for (ll i = 0; i < N; i++) {
    if (s[i] == 'x' && p - 2 >= 0 && v[p - 2] == 'f' && v[p - 1] == 'o') {
      p -= 2;
      v.pop_back();
      v.pop_back();
    }else {
      v.push_back(s[i]);
      p++;
    }
  }
  cout << p << endl;

  return 0;
}

