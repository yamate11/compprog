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

  ll N, M; cin >> N >> M;
  string S; cin >> S;
  vector<ll> prev(N + 1);
  ll p = -1;
  REP(i, 0, N + 1) {
    prev[i] = p;
    if (S[i] == '0') p = i;
  }
  vector<ll> dice(N + 1);
  ll g = N;
  ll c = g;
  while (true) {
    ll cc = prev[c];
    if (cc < 0) break;
    if (g <= cc + M) {
      dice[cc] = g - cc;
      c = cc;
    }else {
      if (c < g) {
        g = c;
      }else {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  vector<ll> ans;
  {
    ll i = 0;
    while (i < N) {
      ans.push_back(dice[i]);
      i += dice[i];
    }
  }
  REPOUT(i, 0, SIZE(ans), ans[i], " ");

  return 0;
}

