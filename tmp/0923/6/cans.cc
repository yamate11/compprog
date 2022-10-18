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

  ll N, K, C; cin >> N >> K >> C;
  string S; cin >> S;
  vector<ll> A(N), B(N);
  auto fill = [&](auto& vec, string ss) -> bool {
    ll cnt = 0;
    for (ll i = 0; i < N; ) {
      if (ss[i] == 'o') {
        vec[i] = 1;
        i += C + 1;
        cnt++;
      }else {
        i++;
      }
    }
    assert(cnt >= K);
    return cnt == K;
  };
  bool b = fill(A, S);
  if (not b) return 0;
  reverse(ALL(S));
  fill(B, S);
  reverse(ALL(B));
  REP(i, 0, N) {
    if (A[i] and B[i]) { cout << i + 1 << "\n"; }
  }
    

  return 0;
}

