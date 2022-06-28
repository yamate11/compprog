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
  if (S.size() == 1) {
    if (S == "8") cout << "Yes\n";
    else cout << "No\n";
    return 0;
  }
  if (S.size() == 2) {
    ll a = S[0] * 10 + S[1];
    ll b = S[1] * 10 + S[0];
    if (a % 8 == 0 or b % 8 == 0) {
      cout << "Yes\n";
    }else {
      cout << "No\n";
    }
    return 0;
  }

  vector<ll> cnt(8);
  for (char c : S) {
    cnt[(c - '0') % 8]++;
  }
  REP(i, 8) {
    if (cnt[i] == 0) continue;
    cnt[i]--;
    REP(j, 8) {
      if (cnt[j] == 0) continue;
      cnt[j]--;
      REP(k, 8) {
        if (cnt[k] == 0) continue;
        if ((i * 4 + j * 2 + k) % 8 == 0) {
          cout << "Yes\n";
          return 0;
        }
      }
      cnt[j]++;
    }
    cnt[i]++;
  }
  cout << "No\n";

  return 0;
}

