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

  ll lim = (ll)1e18;
  ll half = (ll)1e9;
  ll S; cin >> S;
  if (S == lim) {
    cout << "0 0 " << half << " 0 0 " << half << endl;
    return 0;
  }else {
    ll p = S / half;
    ll q = S % half;
    ll a = p + 1;
    ll d = half;
    ll b = half - q;
    ll c = 1;
    cout << "0 0 " << a << " " << b << " " << c << " " << d << endl;
  }

  return 0;
}

