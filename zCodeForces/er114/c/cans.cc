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
  vector<ll> A(N);
  ll tot = 0;
  REP(i, N) {
    cin >> A[i];
    tot += A[i];
  }
  sort(ALL(A));
  ll M; cin >> M;
  REP(j, M) {
    ll X, Y; cin >> X >> Y;
    auto sub = [&](ll p) -> ll {
      ll e1 = max(X - A[p], 0LL);
      ll e2 = max(Y - (tot - A[p]), 0LL);
      return e1 + e2;
    };
    auto func = [&](ll p, ll q) -> void {
      ll t = sub(p);
      if (q >= 0) t = min(t, sub(q));
      cout << t << "\n";
    };
    ll i = lower_bound(A.begin(), A.end(), X) - A.begin();
    if (i == N) func(N-1, -1);
    else if (A[i] == X) func(i, -1);
    else if (i == 0) func(0, -1);
    else func(i, i-1);
  }


  return 0;
}

