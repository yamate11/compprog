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

  ll N; cin >> N;
  string S; cin >> S;
  vector<ll> right, left;
  REP2R(i, N-1, 0) {
    if (S[i] == 'L') right.push_back(i);
    else left.push_back(i);
  }
  reverse(ALL(left));
  for (ll a : left) { cout << a << " "; }
  cout << N;
  for (ll a : right) { cout << " " << a; }
  cout << endl;
  

  return 0;
}

