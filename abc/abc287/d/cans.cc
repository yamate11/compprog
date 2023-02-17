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

  auto comp = [&](char c, char d) -> bool {
    if (c == d) return true;
    if (c == '?' or d == '?') return true;
    return false;
  };

  string S; cin >> S;
  string T; cin >> T;
  ll szS = SIZE(S);
  ll szT = SIZE(T);
  vector<bool> A(szT + 1);
  vector<bool> B(szT + 1);
  A[0] = true;
  REP(i, 0, szT) {
    if (comp(S[i], T[i])) A[i + 1] = A[i];
    else A[i + 1] = false;
  }
  B[0] = true;
  REP(i, 0, szT) {
    if (comp(S[szS - 1 - i], T[szT - 1 - i])) B[i + 1] = B[i];
    else B[i + 1] = false;
  }
  REP(i, 0, szT + 1) {
    if (A[i] and B[szT - i]) cout << "Yes\n";
    else cout << "No\n";
  }


  return 0;
}

