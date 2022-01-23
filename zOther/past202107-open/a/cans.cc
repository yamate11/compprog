#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll odd = 0, even = 0;
  REP(i, 14) {
    ll d = S[i] - '0';
    if (i % 2 == 0) odd += d;
    else even += d;
  }
  ll cd = (odd * 3 + even) % 10;
  if (S[14] - '0' == cd) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }
  

  return 0;
}

