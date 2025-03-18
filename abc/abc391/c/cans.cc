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

  ll N, Q; cin >> N >> Q;
  vector<ll> place(N);
  REP(i, 0, N) place[i] = i;
  vector<ll> num(N);
  REP(i, 0, N) num[i] = 1;
  ll plural = 0;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll p, h; cin >> p >> h; p--; h--;
      ll orig = place[p];
      if (--num[orig] == 1) plural--;
      if (++num[h] == 2) plural++;
      place[p] = h;
    }else if (tp == 2) {
      cout << plural << "\n";
    }
  }
  

  return 0;
}

