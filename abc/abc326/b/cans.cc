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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto judge = [&](ll x) -> bool {
    ll c = x % 10;
    ll y = x / 10;
    ll b = y % 10;
    ll a = y / 10;
    return a * b == c;
  };

  assert(judge(326));
  assert(judge(400));
  assert(judge(144));
  assert(not judge(623));
  assert(not judge(777));
  assert(not judge(429));

  ll N; cin >> N;
  REP(x, N, 1000) {
    if (judge(x)) {
      cout << x << endl;
      return 0;
    }
  }
  

  return 0;
}

