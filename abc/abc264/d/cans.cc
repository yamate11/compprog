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
  vector<ll> a(26);
  string atc = "atcoder";
  REP(i, 7) a[atc[i] - 'a'] = i;
  ll cnt = 0;
  REP(i, 7) REP2(j, i + 1, 7) {
    if (a[S[i] - 'a'] > a[S[j] - 'a']) cnt++;
  }
  cout << cnt << endl;

  return 0;
}
