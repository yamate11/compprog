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
  string t = "atcoder";
  ll N = ssize(t);
  map<char, ll> mp;
  REP(i, 0, N) mp[t[i]] = i;
  vector<ll> vec(N);
  REP(i, 0, N) vec[i] = mp[S[i]];
  ll ans = 0;
  REP(i, 0, N) REP(j, i + 1, N) if (vec[i] > vec[j]) ans++;
  cout << ans << endl;

  return 0;
}
