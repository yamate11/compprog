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

  ll n; cin >> n;
  // @InpVec(n, S, type=string) [qb926ZpM]
  auto S = vector(n, string());
  for (int i = 0; i < n; i++) { string v; cin >> v; S[i] = v; }
  // @End [qb926ZpM]

  vector<ll> vec(26, 1000);
  REP(i, 0, n) {
    vector<ll> v(26);
    for (char c : S[i]) {
      v[c - 'a']++;
    }
    REP(j, 0, 26) vec[j] = min(vec[j], v[j]);
  }
  string s;
  REP(i, 0, 26) s += string(vec[i], (char)('a' + i));
  cout << s << endl;

  return 0;
}

