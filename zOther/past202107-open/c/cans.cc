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

  auto solve = [&]() -> bool {
    string S; cin >> S;
    ll L, R; cin >> L >> R;
    if (S.size() >= 10) return false;
    ll t = stoi(S);
    if (t < L or R < t) return false;
    if (t == 0) {
      return S.size() == 1;
    }else {
      return S[0] != '0';
    }
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

