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

  ll N, K; cin >> N >> K;
  // @InpMVec(N, (A, B)) [8sI07HWE]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [8sI07HWE]

  vector ord(51, vector(N, 0LL));
  REP(x, 1, 51) {
    REP(i, 0, N) ord[x][i] = i;
    sort(ALL(ord[x]),
         [&](ll p, ll q) -> bool {
           return A[p] * x + B[p] > A[q] * x + B[q];
         });
  }
  auto func = [&](auto rF, ll n, ll x, vector<ll>& excl) -> ll {
    if (n == 0) return x;
    ll y = x;
    if (x >= 50) y = 50;
    ll z = 0;
    ll cnt = 0;
    ll res = 0;
    auto in_excl = [&](int i) {
      for (ll e : excl) if (i == e) return true;
      return false;
    };
    REP(ii, 0, N) {
      ll i = ord[y][z++];
      if (in_excl(i)) continue;
      ll val = A[i] * x + B[i];
      excl.push_back(i);
      ll this_res = rF(rF, n - 1, val, excl);
      res = max(res, this_res);
      excl.pop_back();
      cnt++;
      if (cnt == n) break;
    }
    return res;
  };
  vector<ll> init;
  cout << func(func, K, 1, init) << endl;


  return 0;
}

