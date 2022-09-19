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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<string> sA(N);
  REP(i, 0, N) cin >> sA[i];
  sort(ALL(sA), [&](string s1, string s2) -> bool {
    if (SIZE(s1) != SIZE(s2)) return SIZE(s1) > SIZE(s2);
    return s1 > s2;
  });
  vector<string> B;
  B.push_back(sA[0] + sA[1] + sA[2]);
  B.push_back(sA[0] + sA[2] + sA[1]);
  B.push_back(sA[1] + sA[0] + sA[2]);
  B.push_back(sA[1] + sA[2] + sA[0]);
  B.push_back(sA[2] + sA[0] + sA[1]);
  B.push_back(sA[2] + sA[1] + sA[0]);
  sort(ALL(B), greater<string>());
  cout << B[0] << endl;
  

  return 0;
}

