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
  ll leftmost = 0;
  while (leftmost < N && S[leftmost] == '.') leftmost++;
  ll rightmost;
  {
    ll i = N-1;
    while (i >= 0 && S[i] == '.') i--;
    rightmost = N-1 - i;
  }
  ll i = 0;
  ll longest = max(leftmost, rightmost);
  while (i < N) {
    ll i0 = i;
    while (i < N && S[i] == '.') i++;
    longest = max(longest, i - i0);
    while (i < N && S[i] == '#') i++;
  }
  if (leftmost + rightmost >= longest) {
    cout << leftmost << " " << rightmost << endl;
  }else {
    cout << longest - rightmost << " " << rightmost << endl;
  }

  return 0;
}

