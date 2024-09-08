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
  // @InpVec(N, S, type=string) [0epkwCq7]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [0epkwCq7]
  vector A(6, vector<string>());
  REP(i, 0, N) A[ssize(S[i])].push_back(S[i]);
  unordered_map<string, ll> mp;
  ll ans = 0;
  REP(len, 1, 6) {
    for (string& s : A[len]) {
      mp[s]++;
      ans += mp[s] - 1;
      set<string> ss0;
      REP(x, 0, 1LL << len) {
        string t;
        REP(i, 0, len) if (x >> i & 1) t += s[i];
        ss0.insert(t);
      }
      for (string t : ss0) {
        auto it = mp.find(t);
        if (it != mp.end()) ans += it->second;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

