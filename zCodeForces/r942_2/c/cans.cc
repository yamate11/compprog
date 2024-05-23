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
    ll N, K; cin >> N >> K;
    // @InpVec(N, A) [Yjmz46ia]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [Yjmz46ia]
    
    vector<ll> ord(N);
    REP(i, 0, N) ord[i] = i;
    sort(ALL(ord), [&](ll i, ll j) -> bool { return A[i] < A[j]; });
    
    REP(i, 0, N - 1) {
      ll j = ord[i];
      ll d = A[ord[i + 1]] - A[j];
      ll fi = (i + 1) * d;
      if (fi > K) {
        ll p0 = A[j] + K / (i + 1);
        ll r = K % (i + 1);

        /*
        vector<ll> vec(2*N, 0LL);
        REP(k, i + 1, N) vec[ord[k]] = vec[N + ord[k]] = 1;
        
        ll wi = 0;
        ll q = 0;
        ll c = 0;
        REP(p, 0, N) {
          for (;; q++) {
            if (not vec[q]) {
              if (c == r) {
                wi = max(wi, q - p);
                break;
              }
              c++;
            }
          }
          if (not vec[p]) c--;
        }
        */

        cout << N * (p0 - 1) + 1 + r + (N - i - 1) << endl;
        return;
      }
      K -= fi;
    }
    ll p = A[ord[N - 1]] + K / N;
    ll r = K % N;
    cout << N * (p - 1) + 1 + r << endl;
    return;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

