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
    ll N, M; cin >> N >> M;
    // @InpVec(N, A) [Guw2kSqd]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [Guw2kSqd]
    // @InpVec(M, B) [ANZc4LwP]
    auto B = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
    // @End [ANZc4LwP]
    sort(ALL(A));
    sort(ALL(B));
    
    vector<ll> V;
    vector<ll> W;
    REP(i, 0, M) {
      if (i < N - 1 - i) {
        V.push_back(A[N - 1 - i] - A[i]);
      }else {
        break;
      }
    }
    REP(i, 0, N) {
      if (i < M - 1 - i) {
        W.push_back(B[M - 1 - i] - B[i]);
      }
    }
    auto sat = [&](ll p, ll q) -> bool {
      return p + 2 * q <= M and 2 * p + q <= N;
    };

    ll p = 0, q = 0;
    ll cur = 0;
    vector<ll> ans;
    while (true) {
      if (sat(p + 1, q) and sat(p, q + 1)) {
        if (V[p] >= W[q]) {
          cur += V[p];
          p++;
        }else {
          cur += W[q];
          q++;
        }
      }else if (sat(p + 1, q)) {
        cur += V[p];
        p++;
      }else if (sat(p, q + 1)) {
        cur += W[q];
        q++;
      }else {
        if (p + 2 * q + 3 <= M and p > 0) {
          cur -= V[--p];
          cur += W[q++];
          cur += W[q++];
        }else if (q + 2 * p + 3 <= N and q > 0) {
          cur -= W[--q];
          cur += V[p++];
          cur += V[p++];



        }else {
          break;
        }
      }
      ans.push_back(cur);
    }
    cout << ssize(ans) << endl;
    REPOUT(i, 0, ssize(ans), ans[i], " ");


  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

