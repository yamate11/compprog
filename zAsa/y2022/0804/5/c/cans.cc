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

  ll N; cin >> N;
  vector nbr(N, vector<ll>());
  REP(i, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  vector<bool> done(N);
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  pque.push(0);
  vector<ll> ans;
  while (not pque.empty()) {
    ll p = pque.top(); pque.pop();
    done[p] = true;
    ans.push_back(p);
    for (ll q : nbr[p]) if (not done[q]) pque.push(q);
  }
  bool first = true;
  for (ll a : ans) {
    if (first) first = false;
    else cout << " ";
    cout << a + 1;
  }
  cout << "\n";

  return 0;
}

