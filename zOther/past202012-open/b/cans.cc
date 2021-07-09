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
  string T;
  for (ll i = 0; i < N; i++) {
    char c = S[i];
    string prev = move(T);
    T = "";
    for (ll j = 0; j < (ll)prev.size(); j++) {
      if (prev[j] == c) continue;
      T += prev[j];
    }
    T += c;
  }
  cout << T << endl;

  return 0;
}

