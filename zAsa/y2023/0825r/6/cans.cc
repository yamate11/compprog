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

  ll N, K; cin >> N >> K;
  if (N == 1) {
    cout << "Yes\n0 1\n";
    return 0;
  }
  if (K % 2 == 0 or N == K) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  vector<ll> tbl;
  auto f = [&](auto rF, ll st, ll n) -> ll {
    if (n == K + 1) {
      ll cur = st;
      REP(i, 0, 1LL << n) {
        if (i > 0) {
          ll j = __builtin_ctzll(i);
          ll mask = (1LL << n) - 1;
          mask = mask ^ (1LL << j);
          cur = cur ^ mask;
        }
        tbl.push_back(cur);
      }
      return cur;
    }else {
      ll x = rF(rF, st, n - 1);
      ll mask = ((1LL << K) - 1) << (n - K);
      ll y = rF(rF, x ^ mask, n - 1);
      return y;
    }
  };
  f(f, 0, N);
  REPOUT(i, 0, 1LL << N, tbl[i], " ");

  return 0;
}

