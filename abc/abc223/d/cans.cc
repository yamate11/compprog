#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<vector<ll>> nxt(N+1);
  vector<set<ll>> prv(N+1);
  REP(i, M) {
    ll a, b; cin >> a >> b;
    nxt[a].push_back(b);
    prv[b].insert(a);
  }
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  vector<bool> done(N+1);
  REP2(i, 1, N + 1) if (prv[i].empty()) {
    pque.push(i);
    done[i] = true;
  }
  vector<ll> ans;
  while (not pque.empty()) {
    ll x = pque.top(); pque.pop();
    ans.push_back(x);
    for (ll y : nxt[x]) {
      prv[y].erase(x);
      if (prv[y].empty() and not done[y]) {
        done[y] = true;
        pque.push(y);
      }
    }
  }
  if (SIZE(ans) == N) {
    for (ll x : ans) cout << x << " ";
    cout << endl;
  }else {
    cout << -1 << endl;
  }
  

  return 0;
}

