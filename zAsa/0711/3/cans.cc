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

  ll N, Q; cin >> N >> Q;
  vector<ll> A(N); REP(i, 0, N) A[i] = i;
  vector<ll> pos(N); REP(i, 0, N) pos[i] = i;
  REP(_q, 0, Q) {
    ll x; cin >> x; x--;
    ll p = pos[x];
    if (p < N - 1) {
      ll y = A[p + 1];
      A[p] = y;
      A[p + 1] = x;
      pos[y] = p;
      pos[x] = p + 1;
    }else {
      ll y = A[p - 1];
      A[p] = y;
      A[p - 1] = x;
      pos[y] = p;
      pos[x] = p - 1;
    }
  }
  REPOUT(i, 0, N, A[i] + 1, " ");

  return 0;
}

