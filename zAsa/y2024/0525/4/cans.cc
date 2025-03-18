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
  ll N = ssize(S);
  vector<ll> A(N + 1, 0LL);
  ll c = 0;
  A[0] = 0;
  REP(i, 0, N) {
    c ^= 1LL << (S[i] - '0');
    A[i + 1] = c;
  }
  
  vector<ll> B(1024, 0LL);
  ll ans = 0;
  REP(i, 0, N + 1) {
    ll a = A[i];
    ans += B[a];
    B[a] ++;
  }
  cout << ans << endl;
  return 0;
}

