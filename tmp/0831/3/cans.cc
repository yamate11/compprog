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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> cnt(6);
  ll N; cin >> N;
  REP(i, 0, N) {
    double x, y; cin >> x >> y;
    ll xx = llround(x * 10);
    ll yy = llround(y * 10);
    if (350 <= xx) cnt[0]++;
    if (300 <= xx and xx < 350) cnt[1]++;
    if (250 <= xx and xx < 300) cnt[2]++;
    if (250 <= yy) cnt[3]++;
    if (yy < 0 and 0 <= xx) cnt[4]++;
    if (xx < 0) cnt[5]++;
  }
  REPOUT(i, 0, 6, cnt[i], " ");

  return 0;
}

