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
  ll K; cin >> K;

  ll N = ssize(S);
  vector<ll> vec;
  ll p = 0;
  REP(i, 1, N + 1) {
    if (i == N or S[i - 1] != S[i]) {
      vec.push_back(i - p);
      p = i;
      if (i == N) break;
    }
  }
  if (ssize(vec) == 1) {
    cout << (N * K) / 2 << endl;
  }else if (S[0] != S[N - 1]) {
    ll ans = 0;
    for (ll c : vec) {
      ans += K * (c / 2);
    }
    cout << ans << endl;
  }else {
    ll ans = 0;
    ans += (K - 1) * ((vec.back() + vec[0]) / 2);
    ans += 1 * (vec[0] / 2);
    ans += 1 * (vec.back() / 2);
    REP(i, 1, ssize(vec) - 1) {
      ans += K * (vec[i] / 2);
    }
    cout << ans << endl;
  }
  return 0;
}

