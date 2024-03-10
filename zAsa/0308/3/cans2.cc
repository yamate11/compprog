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
  // @InpVec(N, B) [A3UffkyC]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [A3UffkyC]
  
  if (B[0] != 1) {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> nxt(N+2);
  vector<ll> prv(N+2);
  nxt[0] = N + 1;
  prv[N + 1] = 0;
  nxt[N + 1] = -1;
  prv[0] = -1;
  REP(i, 0, N) {
    ll idx = 0;
    REP(j, 0, B[i]) {
      idx = nxt[idx];
      if (idx == -1) {
        cout << -1 << endl;
        return 0;
      }
    }
    nxt[i + 1] = idx;
    prv[i + 1] = prv[idx];
    nxt[prv[i + 1]] = i + 1;
    prv[nxt[i + 1]] = i + 1;
  }
  ll idx = 0;
  REP(i, 0, N) {
    idx = nxt[idx];
    cout << B[idx - 1] << "\n";
  }

  

  return 0;
}

