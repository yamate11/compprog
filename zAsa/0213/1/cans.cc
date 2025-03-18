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
  // @InpMVec(M, ((A, dec=1), (B, type=char))) [Yo76zJH6]
  auto A = vector(M, ll());
  auto B = vector(M, char());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    char v2; cin >> v2; B[i] = v2;
  }
  // @End [Yo76zJH6]

  vector has(N, false);
  REP(i, 0, M) {
    if (B[i] == 'F') {
      cout << "No\n";
    }else if (not has[A[i]]) {
      cout << "Yes\n";
      has[A[i]] = true;
    }else {
      cout << "No\n";
    }
  }

  return 0;
}

