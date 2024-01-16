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

  ll N; cin >> N;
  // @InpVec(N, A) [oLtwUa9j]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [oLtwUa9j]

  ll lim = 200;

  vector L(N + 1, vector(lim, vector<ll>()));
  vector R(N + 1, vector(lim, vector<ll>()));
  REP(i, 0, N) {
    L[i + 1] = L[i];
    REP(j, 0, lim) {
      ll k = (j + A[i]) % lim;
      if (L[i + 1][k].empty() and (j == 0 or not L[i + 1][j].empty())) {
        L[i + 1][k] = L[i + 1][j];
        L[i + 1][k].push_back(i);
      }
    }
  }
  REPrev(i, N - 1, 0) {
    R[i] = R[i + 1];
    REP(j, 0, lim) {
      ll k = (j + A[i]) % lim;
      if (R[i][k].empty() and (j == 0 or not R[i][j].empty())) {
        R[i][k] = R[i][j];
        R[i][k].push_back(i);
      }
    }
  }
  REP(i, 0, N) {
    vector S(lim, vector<ll>());
    REP(p, 0, lim) REP(q, 0, lim) {
      if ((p == 0 or not L[i][p].empty()) and (q == 0 or not R[i + 1][q].empty())) {
        ll r = (p + q) % lim;
        S[r] = L[i][p];
        for (ll x : R[i + 1][q]) S[r].push_back(x);
      }
    }
    REP(r, 0, lim) {
      auto func = [&](auto& vec) -> void {
        sort(ALL(vec));
        cout << SIZE(vec) << " ";
        REPOUT(k, 0, SIZE(vec), vec[k] + 1, " ");
      };
      ll t = (r + A[i]) % lim;
      if (not S[t].empty() and (r == 0 or not S[r].empty())) {
        cout << "Yes\n";
        vector vec = S[t];
        func(vec);
        vector<ll> vec2;
        if (r != 0) vec2 = S[r];
        vec2.push_back(i);
        func(vec2);
        return 0;
      }
    }
  }
  cout << "No\n";

  return 0;
}

