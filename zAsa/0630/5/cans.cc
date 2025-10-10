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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [hBJpCcmO]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [hBJpCcmO]
  // @InpVec(N, B) [0uJtCjyD]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [0uJtCjyD]
  // @InpVec(M, C) [daJazeAu]
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; C[i] = v; }
  // @End [daJazeAu]
  // @InpVec(M, D) [9YCzvp4v]
  auto D = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; D[i] = v; }
  // @End [9YCzvp4v]

  enum kind { Choco, Box };
  using ev_t = tuple<ll, kind, ll, ll>;
  vector<ev_t> ev;
  REP(i, 0, N) ev.emplace_back(A[i], Choco, B[i], i);
  REP(i, 0, M) ev.emplace_back(C[i], Box, D[i], i);
  sort(ALL(ev), greater<ev_t>());
  multiset<ll> sy;
  for (auto [x, kd, y, i] : ev) {
    if (kd == Box) sy.insert(y);
    else if (kd == Choco) {
      auto it = sy.lower_bound(y);
      if (it == sy.end()) {
        cout << "No\n";
        return 0;
      }
      sy.erase(it);
    }else assert(0);
  }
  cout << "Yes\n";

  return 0;
}

