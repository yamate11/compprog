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
  
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  N -= 2;

  ll base = 1;
  REP(k, 1, 1000) {
    if (k > 1 and k % 2 == 1) base *= 10;
    ll c = 9 * base;
    if (N < c) {
      string t1 = to_string(base + N);
      string t2 = t1;
      if (k % 2 == 1) t2.pop_back();
      reverse(ALL(t2));
      cout << t1 << t2 << endl;
      return 0;
    }else {
      N -= c;
    }
  }


  return 0;
}

