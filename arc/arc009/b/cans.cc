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

  vector<ll> B(10), R(10);
  for (ll i = 0; i < 10; i++) {
    ll b; cin >> b;
    B[i] = b;
    R[b] = i;
  }
  auto func = [&](string s) -> ll {
    ll ret = 0;
    for (ll i = 0; i < (ll)s.size(); i++) {
      ret = ret * 10 + R[s[i] - '0'];
    }
    return ret;
  };

  ll N; cin >> N;
  using sta = pair<ll, string>;
  vector<sta> rec(N);
  for (ll i = 0; i < N; i++) {
    string s; cin >> s;
    rec[i] = {func(s), s};
  }
  sort(rec.begin(), rec.end());
  for (auto [d, s] : rec) {
    cout << s << "\n";
  }

  return 0;
}

