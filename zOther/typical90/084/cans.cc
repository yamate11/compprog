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
  string S; cin >> S;
  ll cnt = 0;
  for (ll p = 0; p < N; ) {
    ll q = p;
    for (; q < N && S[p] == S[q]; q++);
    ll n = q - p;
    cnt += n * (n + 1) / 2;
    p = q;
  }
  cout << N * (N + 1) / 2 - cnt << endl;
    
  return 0;
}

