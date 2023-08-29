#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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
  // @InpVec(N, A, type=string) [sC3bIJjG]
  auto A = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; A[i] = v; }
  // @End [sC3bIJjG]
  sort(ALL(A),
       [&](string a, string b) -> bool {
         if (SIZE(a) != SIZE(b)) return SIZE(a) > SIZE(b);
         else return a > b;
       });
  vector<vector<ll>> vec{{0,1,2}, {0,2,1}, {1,2,0}, {1,0,2}, {2,1,0}, {2,0,1}};
  string ans = "";
  for (auto v : vec) {
    string t = A[v[0]] + A[v[1]] + A[v[2]];
    ans = max(ans, t);
  }
  cout << ans << endl;

  return 0;
}

