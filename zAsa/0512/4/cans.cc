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
  string S, T; cin >> S >> T;
  ll sigma = 26;
  vector<ll> cntS(sigma);
  vector<ll> cntT(sigma);
  REP(i, 0, N) {
    cntS[S[i] - 'a']++;
    cntT[T[i] - 'a']++;
  }
  if (cntS != cntT) {
    cout << -1 << endl;
    return 0;
  }
  ll idx = N - 1;
  ll rem = 0;
  REPrev(i, N - 1, 0) {
    while (idx >= 0 and T[idx] != S[i]) idx--;
    if (idx < 0) break;
    rem++;
    idx--;
  }
  cout << N - rem << endl;
  

  return 0;
}

