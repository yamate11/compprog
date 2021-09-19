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

  string X; cin >> X;
  string Y(26, 0);
  for (ll i = 0; i < 26; i++) Y[X[i] - 'a'] = 'a' + i;
  auto tr1 = [&](string s) -> string {
    string ret;
    ll sz = s.size();
    for (ll i = 0; i < sz; i++) {
      ret += Y[s[i] - 'a'];
    }
    return ret;
  };
  auto tr2 = [&](string s) -> string {
    string ret;
    ll sz = s.size();
    for (ll i = 0; i < sz; i++) {
      ret += X[s[i] - 'a'];
    }
    return ret;
  };

  ll N; cin >> N;
  vector<string> S(N);
  for (ll i = 0; i < N; i++) cin >> S[i];
  vector<string> T(N);
  for (ll i = 0; i < N; i++) T[i] = tr1(S[i]);
  sort(T.begin(), T.end());
  for (ll i = 0; i < N; i++) {
    cout << tr2(T[i]) << "\n";
  }

  return 0;
}

