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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(2*N, A) [NiV107N0]
    auto A = vector(2*N, ll());
    for (int i = 0; i < 2*N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [NiV107N0]

    if (N == 1) {
      cout << 1 << "\n";
      return;
    }

    vector posA(N, -1LL);
    vector posB(N, -1LL);
    REP(i, 0, 2*N) {
      if (posA[A[i]] < 0) posA[A[i]] = i;
      else posB[A[i]] = i;
    }

    auto mex = [&](const auto& vec) -> ll {
      vector P(N + 1, false);
      for (ll x : vec) P[x] = true;
      for (ll i = 0; true; i++) if (not P[i]) return i;
      assert(0);
    };

    auto checkA = [&]() -> ll {
      ll m0 = posA[0] + posB[0];
      ll m1 = posA[1] + posB[1];
      if (m0 != m1) return -1;
      vector<ll> vec;
      if (m0 % 2 == 0) {
        ll c = m0 / 2;
        for (ll i = 0; true; i++) {
          if (c + i < 2*N and c - i >= 0 and A[c + i] == A[c - i]) vec.push_back(A[c + i]);
          else break;
        }
      }else {
        ll c0 = m0 / 2;
        ll c1 = c0 + 1;
        for (ll i = 0; true; i++) {
          if (c1 + i < 2*N and c0 - i >= 0 and A[c1 + i] == A[c0 - i]) vec.push_back(A[c1 + i]);
          else break;
        }
      }
      return mex(vec);
    };
    auto checkB = [&](ll x, ll y) -> ll {
      ll m0 = posA[x] + posB[x];
      if (m0 % 2 == 0 and A[m0 / 2] == y) {
        vector<ll> vec;
        ll c = m0 / 2;
        for (ll i = 0; true; i++) {
          if (c + i < 2*N and c - i >= 0 and A[c + i] == A[c - i]) vec.push_back(A[c + i]);
          else break;
        }
        return mex(vec);
      }else return -1;
    };


    ll c1 = checkA();
    ll c2 = checkB(0, 1);
    ll c3 = checkB(1, 0);
    cout << max(max(max(c1, c2), c3), 1LL) << "\n";


  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

