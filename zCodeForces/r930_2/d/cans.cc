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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    string S; cin >> S;
    vector<ll> L, R;
    REP(i, 0, N) {
      if (S[i] == '<') L.push_back(i);
      else R.push_back(i);
    }
    vector<ll> AL(ssize(L) + 1, 0LL);
    vector<ll> AR(ssize(R) + 1, 0LL);
    REP(i, 0, ssize(L)) AL[i + 1] = AL[i] + L[i];
    REP(i, 0, ssize(R)) AR[i + 1] = AR[i] + R[i];
    vector<ll> ans(N);
    ll j0 = 0, k0 = 0;
    REP(i, 0, N) {
      if (S[i] == '<') j0++;
      if (i - 1 >= 0 and S[i - 1] == '>') k0++;
      ll x = ssize(L) - j0;
      ll y = k0;
      ll m = min(x, y);
      ll t = 2 * ((AL[j0 + m] - AL[j0]) - (AR[k0] - AR[k0 - m]));

      if (S[i] == '>') {
        if (x <= y) t += N - i;
        else        t += L[j0 + m] - i + L[j0 + m] - (-1);
      }else {
        if (y <= x) t += i - (-1);
        else        t += i - R[k0 - m - 1] + N - R[k0 - m - 1];
      }
      ans[i] = t;
    }
    REPOUT(i, 0, N, ans[i], " ");

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

