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

  string X; cin >> X;
  REP(i, 0, 26) X[i] -= 'a';
  vector<ll> revX(26);
  REP(i, 0, 26) revX[X[i]] = i;
  auto comp1 = [&](char x, char y) -> bool { return revX[x - 'a'] < revX[y - 'a']; };
  auto comp2 = [&](string s, string t) -> bool {
    REP(i, 0, min(SIZE(s), SIZE(t))) if (s[i] != t[i]) return comp1(s[i], t[i]);
    return SIZE(s) < SIZE(t);
  };
  ll N; cin >> N;
  // @InpVec(N, S, type=string) [TF8DOMZN]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [TF8DOMZN]
  sort(ALL(S), comp2);
  REPOUT(i, 0, N, S[i], "\n");
    

  return 0;
}

