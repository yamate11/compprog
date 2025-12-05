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
  // @InpVec(2*N, V) [9AENaagZ]
  auto V = vector(2*N, ll());
  for (int i = 0; i < 2*N; i++) { ll v; cin >> v; V[i] = v; }
  // @End [9AENaagZ]

  priority_queue<ll, vector<ll>, greater<ll>> pque;
  ll tot = accumulate(ALL(V), 0LL);
  ll aoki = 0;
  REP(i, 0, N) {
    pque.push(V[N + i]);
    pque.push(V[N - 1 - i]);
    aoki += pque.top();
    pque.pop();
  }
  cout << tot - aoki << endl;


  return 0;
}

