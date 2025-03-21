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
  // @InpMVec(N, ((S, type=string), (T, type=string))) [XgYyzwS2]
  auto S = vector(N, string());
  auto T = vector(N, string());
  for (int i = 0; i < N; i++) {
    string v1; cin >> v1; S[i] = v1;
    string v2; cin >> v2; T[i] = v2;
  }
  // @End [XgYyzwS2]
  map<string, int> RS;
  REP(i, 0, N) RS[S[i]] = i;

  set<string> seen;
  REP(i, 0, N) {
    ll j = i;
    while (true) {
      auto [_it, b] = seen.emplace(S[j]);
      if (not b) break;
      auto it = RS.find(T[j]);
      if (it == RS.end()) break;
      j = it->second;
      if (j == i) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";

  return 0;
}

