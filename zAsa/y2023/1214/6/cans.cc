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

using u64 = unsigned long long;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  
  vector left(N, vector<ll>());
  vector right(N, vector<ll>());
  ll seq = 0;
  vector<pll> rec;
  REP(k, 0, 100) {
    ll t = 1LL << k;
    if (t > N) break;
    REP(i, 0, N) {
      if (i + t > N) break;
      rec.emplace_back(i, i + t - 1);
      left[i].push_back(seq);
      right[i + t - 1].push_back(seq);
      seq++;
    }
  }
  ll M = seq;
  cout << M << endl;
  for (auto [l, r] : rec) cout << l + 1 << " " << r + 1 << endl;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r; l--; r--;
    ll t = countr_zero(bit_floor((u64)(r - l + 1)));
    ll a = left[l][t];
    ll b = right[r][t];
    cout << a + 1 << " " << b + 1 << endl;
  }


  return 0;
}

