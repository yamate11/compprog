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

  ll T, N; cin >> T >> N;
  // @InpVec(N, A) [AUobQYho]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [AUobQYho]
  ll M; cin >> M;
  // @InpVec(M, B) [yCgt5hpR]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [yCgt5hpR]

  enum kind { AA, BB };
  using ev_t = pair<ll, kind>;
  vector<ev_t> ev;
  REP(i, 0, N) ev.emplace_back(A[i], AA);
  REP(i, 0, M) ev.emplace_back(B[i], BB);
  ranges::sort(ev);
  queue<ll> que;
  for (auto [t, k] : ev) {
    if (k == AA) que.push(t);
    else {
      auto check = [&]() -> bool {
        while (not que.empty()) {
          ll t1 = que.front(); que.pop();
          if (t - t1 <= T) return true;
        }
        return false;
      };
      if (not check()) {
        cout << "no\n";
        return 0;
      }
    }
  }
  cout << "yes\n";

  return 0;
}

