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
  deque<ll> deq;
  REP(i, 0, N) {
    ll a; cin >> a;
    deq.push_back(a);
  }
  sort(ALL(deq));
  ll cnt = 0;
  while (ssize(deq) > 1) {
    ll x = deq.front();
    ll y = deq.back(); deq.pop_back();
    ll r = y % x;
    if (r > 0) deq.push_front(r);
    cnt++;
  }
  cout << cnt << endl;

  return 0;
}

