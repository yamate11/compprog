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

  ll N, Q; cin >> N >> Q;
  string S; cin >> S;
  // @InpMVec(Q, ((T, type=char), (D, type=char))) [E0XXGnZF]
  auto T = vector(Q, char());
  auto D = vector(Q, char());
  for (int i = 0; i < Q; i++) {
    char v1; cin >> v1; T[i] = v1;
    char v2; cin >> v2; D[i] = v2;
  }
  // @End [E0XXGnZF]

  ll l = -1, r = N;
  REPrev(q, Q - 1, 0) {
    if (D[q] == 'L') {
      if (T[q] == S[l + 1]) l++;
      if (r <= N - 1 and T[q] == S[r]) r++;
    }else if (D[q] == 'R') {
      if (l >= 0 and T[q] == S[l]) l--;
      if (T[q] == S[r - 1]) r--;
    }else assert(0);
  }
  cout << N - (l + 1 + N - r) << endl;

  return 0;
}

