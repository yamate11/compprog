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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [oZ0NOwvl]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [oZ0NOwvl]
  // @InpVec(N, B) [QVlexq7Q]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [QVlexq7Q]
  
  bool a = true, b = true;
  REP(i, 1, N) {
    bool prev_a = a;
    bool prev_b = b;
    a = b = false;
    if (prev_a and abs(A[i] - A[i - 1]) <= K) a = true;
    if (prev_b and abs(A[i] - B[i - 1]) <= K) a = true;
    if (prev_a and abs(B[i] - A[i - 1]) <= K) b = true;
    if (prev_b and abs(B[i] - B[i - 1]) <= K) b = true;
  }
  if (a or b) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

