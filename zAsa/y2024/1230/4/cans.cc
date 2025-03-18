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
  ll M = bit_width((u64)N - 1);
  cout << M << endl;
  vector vec(M, vector<ll>());
  REP(i, 0, N) {
    REP(j, 0, M) {
      if (i >> j & 1) vec[j].push_back(i);
    }
  }
  REP(i, 0, M) {
    cout << ssize(vec[i]);
    REP(j, 0, ssize(vec[i])) {
      cout << " " << vec[i][j] + 1;
    }
    cout << endl;
  }
  string S; cin >> S;
  u64 ans = 0;
  REP(i, 0, M) {
    if (S[i] == '1') ans |= 1ULL << i;
  }
  cout << ans + 1 << endl;
  

  return 0;
}

