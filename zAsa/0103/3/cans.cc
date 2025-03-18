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
  set<ll> rem;
  multiset<ll, greater<ll>> pairs;
  REP(i, 0, N) {
    ll a; cin >> a;
    if (rem.contains(a)) {
      pairs.insert(a);
      rem.erase(a);
    }else {
      rem.insert(a);
    }
  }
  if (ssize(pairs) <= 1) {
    cout << 0 << endl;
  }else {
    auto it = pairs.begin();
    ll a = *it;
    pairs.erase(it);
    it = pairs.begin();
    ll b = *it;
    cout << a * b << endl;
  }

  return 0;
}

