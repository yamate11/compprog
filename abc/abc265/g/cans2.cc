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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [PPF0t1Wz]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [PPF0t1Wz]
  ll sz = sqrt(N);
  ll asz = (N + sz - 1) / sz;
  vector summary(3, vector(asz, 0LL));
  REP(i, 0, asz) {
    REP(j, 0, sz) {
      ll x = i * sz + j;
      if (x < N) summary[A[x]][i] ++;
    }
  }
  vector cvt(3, vector(asz, 0LL));
  REP(i, 3) REP(j, asz) cvt[i][j] = i;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll L, R; cin >> L >> R; L--;
      ll p = L / sz;
      ll q = R / sz;
      if (p == q) {
        
      }else {
      }
      
    }else if (tp == 2) {
      ll L, R; cin >> L >> R; L--;
      vector(3) mod;
      REP(i, 3) cin >> mod[i];
      auto block_mod(ll p, ll u, ll v) -> void {
        REP(i, p * sz, min((p + 1) * sz, N)) A[i] = cvt[A[i]][p];
        REP(i, 3) cvt[i][p] = i;
        REP(i, u, v) {
          ll a = A[i];
          ll b = mod[a];
          A[i] = b;
          summary[a][p]--;
          summary[b][p]++;
        }
      };
      ll p = L / sz;
      ll q = R / sz;
      if (p == q) {
        block_mod(p, L, R);
      }else {
        block_mod(p, L, (p + 1) * sz);
        block_mod(q, q * sz, R);
        REP(r, p + 1, q) {
          vector<ll> new_cnt(3, 0LL);
          REP(i, 3) {
            ll a = cvt[i][r];
            ll b = mod[a];
            cvt[i][r] = b;
            new_cnt[b] += summary[a][r];
          }
          REP(i, 3) summary[i][r] = new_cnt[i];
        }
      }
    }
  }

  return 0;
}

