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
  vector<ll> vec1(N);
  vector<ll> vec2(N);
  ll cnt1 = 0;
  REP(i, 0, N) {
    if (S[i] == '0') vec1[i] = cnt1;
    else cnt1++;
  }
  ll cnt2 = 0;
  REPrev(i, N - 1, 0) {
    if (S[i] == '0') vec2[i] = cnt2;
    else cnt2++;
  }
  ll ans = 0;
  REP(i, 0, N) {
    if (S[i] == '0') {
      ll x = min(vec1[i], vec2[i]);
      ans += x;
    }
  }
  cout << ans << endl;
  return 0;
}

