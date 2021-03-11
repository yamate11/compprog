#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = []() -> bool {
    string s; cin >> s;
    vector<ll> vec(26);
    for (ll i = 0; i < (ll)s.size(); i++) {
      vec[s[i] - 'a']++;
    }
    ll n = 0;
    vector<ll> vec2(4);
    for (ll i = 0; i < 26; i++) {
      if (vec[i] > 0) {
        if (n >= 4) return false;
        vec2.push_back(vec[i]);
        n++;
      }
    }
    sort(vec2.begin(), vec2.end(), greater<ll>());
    if (n == 1) return false;
    if (n == 2) return vec2[0] >= 2 && vec2[1] >= 2;
    if (n == 3) return vec2[0] >= 2;
    if (n == 4) return true;
    assert(0);
      
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

