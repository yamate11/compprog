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

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((X, dec=1), (Y, dec=1))) [CdRPpg7A]
  auto X = vector(M, ll());
  auto Y = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; v2 -= 1; Y[i] = v2;
  }
  // @End [CdRPpg7A]
  vector nbr(N, vector<ll>());
  vector<ll> numUp(N);
  REP(i, 0, M) {
    nbr[X[i]].push_back(Y[i]);
    numUp[Y[i]]++;
  }
  ll tops = 0;
  REP(i, 0, N) if (numUp[i] == 0) tops |= 1LL << i;
  vector tbl(1LL << N, -1LL);
  auto func = [&](auto rF, ll rem, ll from) -> ll {
    ll& ret = tbl[rem];
    if (ret < 0) {
      if (rem == 0) ret = 1;
      else {
        if (from >= 0) {
          tops ^= (1LL << from);
          for (ll j : nbr[from]) {
            numUp[j]--;
            if (numUp[j] == 0) tops |= (1LL << j);
          }
        }
        ret = 0;
        REP(i, 0, N) if (tops >> i & 1) {
          ret += rF(rF, rem ^ (1LL << i), i);
        }
        if (from >= 0) {
          for (ll j : nbr[from]) {
            if (numUp[j] == 0) tops ^= (1LL << j);
            numUp[j]++;
          }
          tops |= (1LL << from);
        }
      }
    }
    return ret;
  };
  cout << func(func, (1LL << N) - 1, -1) << endl;

  return 0;
}

