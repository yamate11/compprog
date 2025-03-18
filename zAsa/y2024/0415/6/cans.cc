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
  vector<ll> cnt(M);
  ll lim = 1e5;
  vector<ll> pair(M);
  vector<ll> tmp(lim + 1);
  REP(i, 0, N) {
    ll x; cin >> x;
    cnt[x % M]++;
    if (tmp[x] == 1) {
      pair[x % M]++;
      tmp[x] = 0;
    }else {
      tmp[x] = 1;
    }
  }
  ll ans = cnt[0] / 2;
  REP(i, 1, (M + 1) / 2) {
    ll a = i;
    ll b = M - i;
    ll x = cnt[a];
    ll y = cnt[b];
    if (x < y) {
      swap(a, b);
      swap(x, y);
    }
    ans += y + min(pair[a], (x - y) / 2);
  }
  if (M % 2 == 0) {
    ans += cnt[M / 2] / 2;
  }
  cout << ans << endl;

  return 0;
}

