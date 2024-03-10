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
  using bs_t = bitset<3000>;
  vector<bs_t> bs(N);
  REP(i, 0, N) {
    string s; cin >> s;
    REP(j, 0, N) bs[i][j] = (s[j] == '1');
  }
  ll ans = 0;
  bs_t mask_i; mask_i.set();
  REP(i, 0, N) {
    mask_i[i] = 0;
    bs_t mask_j = mask_i;
    REP(j, i + 1, N) {
      mask_j[j] = 0;
      if (bs[i][j]) {
        ans += (bs[i] & bs[j] & mask_j).count();
      }
    }
  }
  cout << ans << endl;
  return 0;
}

