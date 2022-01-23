#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, N; cin >> A >> N;
  using sta = pair<ll, ll>;
  queue<sta> que;
  ll lim = 1e7;
  vector<bool> seen(lim);
  seen[1] = true;
  que.emplace(1, 0);
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  while (not que.empty()) {
    auto [t, k] = que.front(); que.pop();
    ll t1 = t * A;
    if (t1 == N) {
      cout << k + 1 << endl;
      return 0;
    }
    if (t1 < lim && not seen[t1]) {
      seen[t1] = true;
      que.emplace(t1, k + 1);
    }
    if (t >= 10 and t % 10 != 0) {
      string s = to_string(t);
      ll sz = SIZE(s);
      string ss = s.substr(sz - 1) + s.substr(0, sz - 1);
      ll t2 = stoll(ss);
      if (t2 == N) {
        cout << k + 1 << endl;
        return 0;
      }
      if (t2 < lim && not seen[t2]) {
        seen[t2] = true;
        que.emplace(t2, k + 1);
      }
    }
    
    
  }
  cout << -1 << endl;


  return 0;
}

