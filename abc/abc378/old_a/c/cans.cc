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
  map<ll, ll> mp;
  vector<ll> ans(N);
  REP(i, 0, N) {
    ll a; cin >> a;
    auto it = mp.find(a);
    if (it == mp.end()) {
      ans[i] = -1;
    }else {
      ans[i] = it->second + 1;
    }
    mp[a] = i;
  }
  REPOUT(i, 0, N, ans[i] , " ");

  return 0;
}

