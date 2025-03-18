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

  ll N, M; cin >> N >> M;
  string S, T; cin >> S >> T;
  ll cur = 1LL << (M - 1);
  REP(i, 0, N) {
    ll prv = cur;
    cur = 0;
    REP(j, 0, M) {
      if (T[j] == S[i]) {
        if (j == 0) {
          cur |= 1LL << j;
        }else if (prv >> (M - 1) & 1) {
          cur |= 1LL << j;
        }else if (prv >> (j - 1) & 1) {
          cur |= 1LL << j;
        }
      }
    }
    if (cur == 0) {
      cout << "No\n";
      return 0;
    }
    if (i == 0) {
      if (cur >> 0 & 1) {
        cur = 1;
      }else {
        cout << "No\n";
        return 0;
      }
    }

  }
  if (cur >> (M - 1) & 1) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }
    

  return 0;
}

