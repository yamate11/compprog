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

  ll N, Q; cin >> N >> Q;
  vector<ll> A(2*N);
  REP(i, 0, N) {
    ll a; cin >> a;
    A[i] = A[i + N] = a;
  }
  vector<ll> B(2*N + 1);
  REP(i, 0, 2*N) B[i + 1] = B[i] + A[i];
  ll p = 0;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll c; cin >> c;
      p = (p + c) % N;
    }else if (tp == 2) {
      ll l, r; cin >> l >> r; l--;
      cout << B[p + r] - B[p + l] << "\n";
    }else assert(0);
  }
  


  return 0;
}

