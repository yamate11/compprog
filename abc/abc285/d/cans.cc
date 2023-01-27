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
  // @InpMVec(N, ((S, type=string), (T, type=string))) [Q6h22U7d]
  auto S = vector(N, string());
  auto T = vector(N, string());
  for (int i = 0; i < N; i++) {
    string v1; cin >> v1; S[i] = v1;
    string v2; cin >> v2; T[i] = v2;
  }
  // @End [Q6h22U7d]
  map<string, string> f, g;
  set<string> cur;
  vector<string> ready;
  REP(i, 0, N) {
    f[S[i]] = T[i];
    g[T[i]] = S[i];
    cur.insert(S[i]);
  }
  REP(i, 0, N) {
    if (cur.find(T[i]) == cur.end()) ready.push_back(T[i]);
  }
  while (not ready.empty()) {
    string t = ready.back(); ready.pop_back();
    string s = g[t];
    cur.erase(s);
    auto it = g.find(s);
    if (it != g.end()) ready.push_back(s);
  }
  if (cur.empty()) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

