#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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
  vector<ll> vB, vK, vR;
  REP(i, 0, ssize(S)) {
    if (S[i] == 'B') vB.push_back(i);
    if (S[i] == 'K') vK.push_back(i);
    if (S[i] == 'R') vR.push_back(i);
  }
  if ((vB[0] + vB[1]) % 2 != 0 and vR[0] < vK[0] and vK[0] < vR[1]) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }
  
  

  return 0;
}

