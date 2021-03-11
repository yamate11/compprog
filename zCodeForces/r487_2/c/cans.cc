#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll width = 50;
  ll a, b, c, d; cin >> a >> b >> c >> d;
  vector<string> vec;
  auto func = [&](char x, char y, ll n) -> void {
    string uni(width, x);
    while (n > 0) {
      vec.push_back(uni);
      string s(width, x);
      for (ll i = 0; i < width / 2; i++) {
        if (i < n) s[2*i] = y;
      }
      vec.push_back(s);
      n -= width / 2;
    }
    vec.push_back(uni);
  };

  func('A', 'B', b-1);
  func('A', 'C', c);
  func('B', 'D', d);
  func('B', 'A', a-1);
  cout << vec.size() << " " << width << "\n";
  for (string s : vec) {
    cout << s << "\n";
  }
  return 0;
}

