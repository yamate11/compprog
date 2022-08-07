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
  vector<ll> V(2*N);
  REP(i, 2*N) cin >> V[i];
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  ll in = 0, out = 0;
  REP(i, N) {
    ll a = V[N - 1 - i];
    ll b = V[N + i];
    pque.push(a);
    pque.push(b);
    ll c = pque.top(); pque.pop();
    in += a + b;
    out += c;
  }
  cout << in - out << endl;

  return 0;
}

