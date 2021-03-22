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

  ll N, M; cin >> N >> M;
  ll en = 0;
  ll on = 0;
  for (ll i = 0; i < N; i++) {
    string S; cin >> S;
    ll cnt = 0;
    for (ll j = 0; j < M; j++) {
      if (S[j] == '1') cnt++;
    }
    if (cnt % 2 == 0) en++;
    else on++;
  }
  cout << en * on << endl;
  return 0;
}

