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

using u64 = unsigned long long;

ll ask(ll i) {
  cout << "? " << i + 1 << endl;   // 0-index 等はここで調整
  ll x; cin >> x;
  return x;
}

void fin(ll i) {
  cout << "! " << (i >= 0 ? i + 1 : -1) << endl;
  exit(0);
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  u64 N; cin >> N;
  u64 CM = bit_ceil(N);
  u64 M = 63 - countl_zero(CM);
  vector A(M, vector<ll>());
  REP(i, 0, (ll)N) {
    REP(j, 0, (ll)M) {
      if (i >> j & 1) A[j].push_back(i);
    }
  }
  cout << M << endl;
  REP(j, 0, (ll)M) {
    cout << SIZE(A[j]);
    for (ll x : A[j]) cout << " " << x + 1;
    cout << endl;
  }
  string S; cin >> S;
  reverse(ALL(S));
  ll ans = 0;
  REP(j, 0, (ll)M) ans = ans * 2 + (S[j] - '0');
  cout << ans + 1 << endl;
  
  

  return 0;
}

