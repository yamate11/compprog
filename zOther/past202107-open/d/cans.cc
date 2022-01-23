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
  auto match = [&](ll i) -> bool {
    if (S[i + 1] != 'x') return false;
    if (S[i] != S[i + 2]) return false;
    if (S[i] == 'a') return true;
    if (S[i] == 'e') return true;
    if (S[i] == 'i') return true;
    if (S[i] == 'o') return true;
    if (S[i] == 'u') return true;
    return false;
  };
  REP(i, N - 2) {
    if (match(i)) {
      REP(j, 3) S[i + j] = '.';
    }
  }
  cout << S << endl;

  return 0;
}

