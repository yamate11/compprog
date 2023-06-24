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
  // @InpVec(N, S, type=string) [0QwLXN90]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [0QwLXN90]
  
  ll ans = 0;
  REP(start, 0, N) {
    vector<ll> rank(N, -1LL);
    rank[start] = 1;
    queue<ll> que;
    que.push(start);
    while (not que.empty()) {
      ll nd = que.front(); que.pop();
      REP(i, 0, N) if (S[nd][i] == '1') {
        if (rank[nd] == rank[i]) {
          cout << "-1\n";
          return 0;
        }else if (rank[i] < 0) {
          rank[i] = rank[nd] + 1;
          ans = max(ans, rank[i]);
          que.push(i);
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}

