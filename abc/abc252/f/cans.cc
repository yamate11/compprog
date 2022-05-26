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

  ll N, L; cin >> N >> L;
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  ll rem = L;
  REP(i, N) {
    ll a;
    cin >> a;
    pque.push(a);
    rem -= a;
  }
  if (rem > 0) pque.push(rem);
  ll cost = 0;
  while (pque.size() > 1) {
    ll x = pque.top(); pque.pop();
    ll y = pque.top(); pque.pop();
    cost += x + y;
    pque.push(x + y);
  }
  cout << cost << endl;
  

  return 0;
}

