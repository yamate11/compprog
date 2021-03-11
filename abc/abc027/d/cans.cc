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
  ll N = S.size();
  using St1 = pair<ll, ll>;
  vector<St1> vec;
  {
    ll ht = 0;
    for (ll i = 0; i < N; i++) {
      if (S.at(i) == '+') ht++;
      else if (S.at(i) == '-') ht--;
      else {
	vec.emplace_back(ht, i);
      }
    }
  }
  ll numM = vec.size();
  sort(vec.begin(), vec.end());
  vector<ll> vec2(N);
  for (ll i = 0; i < numM; i++) {
    auto [ht, j] = vec.at(i);
    if (i < numM / 2) {
      vec2.at(j) = +1;
    }else {
      vec2.at(j) = -1;
    }
  }
  ll ans = 0;
  {
    ll cur = 0;
    for (ll i = 0; i < N; i++) {
      if (S.at(i) == '+') ans += cur;
      else if (S.at(i) == '-') ans -= cur;
      else cur += vec2.at(i);
    }
  }

  cout << ans << endl;
  return 0;
}

