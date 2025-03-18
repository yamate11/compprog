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

bool mycomp2(ll a, ll b) {
  return a > b;
}

int bar() { return 1; };

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  set<ll, greater<ll>> ss{greater<ll>()};
  ss.insert(1);
  ss.insert(10);
  ss.insert(4);
  for (ll x : ss) cout << x << endl;

  // auto mycomp = [&](ll a, ll b) -> bool { return a > b; };
  set<ll, bool (*)(ll, ll)> ss2{mycomp2};
  ss2.insert(2);
  ss2.insert(20);
  ss2.insert(8);
  for (ll x : ss2) cout << x << endl;

  vector<ll> vec{3, 30, 15, 12};
  // auto mycomp0 = greater<ll>();
  // auto mycomp0 = mycomp2;
  auto mycomp0 = [&](int a, int b) -> bool { return a > b; };
  sort(vec.begin(), vec.end(), mycomp0);
  auto it = lower_bound(ALL(vec), 15, mycomp0);
  cout << *it << endl;
  it = lower_bound(ALL(vec), 14, mycomp0);
  cout << *it << endl;

  return 0;
}

