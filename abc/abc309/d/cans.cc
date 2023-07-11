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

  ll N1, N2, M; cin >> N1 >> N2 >> M;
  // @InpMVec(M, ((A, dec=1), (B, dec=1))) [NeiAkZgK]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [NeiAkZgK]

  vector nbr1(N1, vector<ll>());
  vector nbr2(N2, vector<ll>());
  REP(i, 0, M) {
    ll a = A[i];
    ll b = B[i];
    if (a < N1) {
      nbr1[a].push_back(b);
      nbr1[b].push_back(a);
    }else {
      a = N1 + N2 - 1 - a;
      b = N1 + N2 - 1 - b;
      nbr2[a].push_back(b);
      nbr2[b].push_back(a);
    }
  }
  auto f = [&](auto& nbr) -> ll {
    ll N = SIZE(nbr);
    ll big = 1e18;
    vector<ll> dist(N, big);
    dist[0] = 0;
    queue<ll> que;
    que.push(0);
    while (not que.empty()) {
      ll x = que.front(); que.pop();
      for (ll y : nbr[x]) {
        if (dist[y] >= big) {
          dist[y] = dist[x] + 1;
          que.push(y);
        }
      }
    }
    return *max_element(ALL(dist));
  };

  ll x = f(nbr1);
  ll y = f(nbr2);
  cout << x + y + 1 << endl;

  return 0;
}

