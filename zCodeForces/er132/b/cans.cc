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

  ll N, M; cin >> N >> M;
  vector<ll> A(N), B(N - 1), C(N - 1), S(N), T(N);
  REP(i, N) cin >> A[i];
  REP(i, N - 1) {
    B[i] = max(A[i] - A[i + 1], 0LL);
    C[i] = max(A[N - 1 - i] - A[N - 2 - i], 0LL);
  }
  REP(i, N - 1) {
    S[i + 1] = S[i] + B[i];
    T[i + 1] = T[i] + C[i];
  }
  REP(i, M) {
    ll s, t; cin >> s >> t; s--; t--;
    if (s < t) {
      cout << S[t] - S[s] << "\n";
    }else if (s > t) {
      cout << T[N - 1 - t] - T[N - 1 - s] << "\n";
    }else assert(0);
  }


  return 0;
}

