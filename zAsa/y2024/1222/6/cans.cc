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
  map<ll, vector<ll>> mp;
  REP(i, 0, M) {
    ll x, y; cin >> x >> y;
    mp[x].push_back(y);
  }

  set<ll> cur;
  cur.insert(N);
  for (auto& [x, ys] : mp) {
    vector<ll> add;
    vector<ll> rem;
    for (ll y : ys) {
      if (cur.contains(y) and not cur.contains(y - 1) and not cur.contains(y + 1)) rem.push_back(y);
      if (not cur.contains(y) and (cur.contains(y - 1) or cur.contains(y + 1) )) add.push_back(y);
    }
    for (ll y : add) cur.insert(y);
    for (ll y : rem) cur.erase(y);
  }
  cout << ssize(cur) << endl;

  return 0;
}

