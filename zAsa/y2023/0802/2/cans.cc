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

  string s; cin >> s;
  ll N = SIZE(s);
  vector<ll> A(3);
  ll r = 0;
  REP(i, 0, N) {
    A[(s[i] - '0') % 3]++;
    r += s[i] - '0';
  }
  r = r % 3;
  ll req = -1;
  if (r == 0) req = 0;
  else if (r == 1) {
    if (A[1] >= 1) req = 1;
    else if (A[2] >= 2) req = 2;
    else req = -1;
  }else if (r == 2) {
    if (A[2] >= 1) req = 1;
    else if (A[1] >= 2) req = 2;
    else req = -1;
  }else assert(0);
  if (req < 0 or req == N) {
    cout << -1 << endl;
  }else {
    cout << req << endl;
  }
  return 0;
}

