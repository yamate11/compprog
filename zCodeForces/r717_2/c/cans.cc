#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll g = 0;
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
    g = gcd(g, A[i]);
  }
  REP(i, N) { A[i] /= g; }
  ll s = 0; REP(i, N) s += A[i];
  if (s % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll lim = s / 2;
  vector<bool> tbl = vector(lim + 1, false);
  tbl[0] = true;
  REP(n, N) {
    REP2R(i, lim, A[n]) {
      if (tbl[i - A[n]]) tbl[i] = true;
    }
  }
  if (not tbl[lim]) {
    cout << 0 << endl;
    return 0;
  }
  cout << 1 << endl;
  REP(i, N) if (A[i] % 2 != 0) {
    cout << i + 1 << endl;
    return 0;
  }
  assert(0);
}

