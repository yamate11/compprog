#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  string T; cin >> T;
  vector<ll> vec1(26), vec2(26);
  ll at1 = 0, at2 = 0;
  for (char c : S) {
    if (c == '@') at1++;
    else vec1[c - 'a']++;
  }
  for (char c : T) {
    if (c == '@') at2++;
    else vec2[c - 'a']++;
  }
  vector<bool> cble(26, false);
  for (char c : string("atcoder")) {
    cble[c - 'a'] = true;
  }
  REP(i, 0, 26) {
    if (vec1[i] == vec2[i]) continue;
    if (not cble[i]) {
      cout << "No\n";
      return 0;
    }
    if (vec1[i] > vec2[i]) at2 -= vec1[i] - vec2[i];
    else at1 -= vec2[i] - vec1[i];
  }
  if (at1 >= 0 and at2 >= 0) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }


  return 0;
}

