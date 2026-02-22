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

  ll N; cin >> N;
  // @InpGrid(N, N, A) [99ArUVjk]
  auto A = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [99ArUVjk]

  vector<ll> room(N, 0LL);
  vector<ll> score(N, 0LL);
  REP(i, 0, N) REP(j, 0, N) score[i] += A[i][j];
  while (true) {
    auto check = [&]() -> bool {
      REP(i, 0, N) {
        if (score[i] >= 0) continue;
        REP(j, 0, N) {
          if (j == i) continue;
          if (room[j] == room[i]) score[j] -= 2 * A[i][j];
          else score[j] += 2 * A[i][j];
        }
        score[i] = -score[i];
        room[i] = 1 - room[i];
        return false;
      }
      return true;
    };
    if (check()) break;
  }
  REP(i, 0, N) cout << (room[i] == 0 ? "X" : "Y");
  cout << endl;

  return 0;
}

