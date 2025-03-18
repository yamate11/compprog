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
  ll cur = 0;
  vector<ll> pos2disk(N + 1), disk2pos(N + 1);
  REP(i, 0, N + 1) {
    pos2disk[i] = i;
    disk2pos[i] = i;
  }
  REP(i, 0, M) {
    ll d; cin >> d;
    ll p = disk2pos[d];
    pos2disk[p] = cur;
    disk2pos[cur] = p;
    disk2pos[d] = 0;
    cur = d;
  }
  REPOUT(i, 1, N + 1, pos2disk[i], "\n");

  return 0;
}

