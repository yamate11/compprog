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

  string S; cin >> S;
  ll n = ssize(S);
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll k; cin >> k; k--;
    ll p = k / n;
    ll q = k % n;
    ll c = popcount((u64)p);
    char ans = S[q];
    if (c % 2 != 0) {
      if ('a' <= ans and ans <= 'z') ans = ans + 'A' - 'a';
      else                           ans = ans + 'a' - 'A';
    }
    cout << ans << " ";
  }
  cout << endl;

  return 0;
}

