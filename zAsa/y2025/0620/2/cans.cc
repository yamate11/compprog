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

  ll N; cin >> N;
  string S; cin >> S;
  string ans;
  REPrev(i, N - 1, 0) {
    if (i == N - 1) {
      if (S[i] == '1') {
        REP(j, 0, N) ans.push_back('A');
      }
    }else {
      if (S[i] != S[i + 1]) {
        char c;
        if (S[i] == '1') c = 'A';
        else c = 'B';
        REP(j, 0, i + 1) ans.push_back(c);
      }
    }
  }
  cout << ssize(ans) << endl;
  cout << ans << endl;

  return 0;
}

