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

  ll N, M, L; cin >> N >> M >> L;
  // @InpVec(N, A) [qXIy2xCF]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [qXIy2xCF]
  // @InpVec(M, B) [uV5OAQ9c]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [uV5OAQ9c]
  // @InpVec(L, C) [ARlTxjAJ]
  auto C = vector(L, ll());
  for (int i = 0; i < L; i++) { ll v; cin >> v; C[i] = v; }
  // @End [ARlTxjAJ]

  ll P = N + M + L;
  vector<ll> vec;
  REP(i, 0, N) vec.push_back(A[i]);
  REP(i, 0, M) vec.push_back(B[i]);
  REP(i, 0, L) vec.push_back(C[i]);
  map<pll, bool> mp;
  auto func = [&](auto rF, ll x, ll y) -> bool {
    auto p = pll(x, y);
    auto it = mp.find(p);
    if (it != mp.end()) return it->second;
    auto sub = [&]() -> bool {
      ll z = ((1LL << P) - 1) ^ (x | y);
      REP(i, 0, P) if (x >> i & 1) {
        if (rF(rF, y, x ^ (1LL << i))) return false;
        REP(j, 0, P) if (z >> j & 1 and vec[j] < vec[i]) {
          if (rF(rF, y, x ^ ((1LL << i) | (1LL << j)))) return false;
        }
      }
      return true;
    };
    bool res = sub();
    mp[p] = res;
    return res;
  };
  ll x0 = (1LL << N) - 1;
  ll y0 = (1LL << (N + M)) - 1 - x0;
  if (func(func, x0, y0)) {
    cout << "Aoki\n";
  }else {
    cout << "Takahashi\n";
  }


  return 0;
}

