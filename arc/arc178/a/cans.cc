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
  // @InpVec(M, A, dec=1) [GbrEvRLf]
  auto A = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [GbrEvRLf]
  sort(ALL(A));
  if (A[0] == 0 or A.back() == N - 1) {
    cout << -1 << endl;
    return 0;
  }
  ll p = 0;
  ll i = 0;
  vector<ll> ans;
  while (p < M) {
    while (i < A[p]) {
      ans.push_back(i);
      i++;
    }
    ll q = p;
    while (true) {
      ans.push_back(A[p] + 1);
      if (p + 1 == M or A[p] + 1 != A[p + 1]) break;
      p++;
    }
    ans.push_back(A[q]);
    i = A[p] + 2;
    p++;
  }
  while (i < N) {
    ans.push_back(i);
    i++;
  }
  REPOUT(j, 0, ssize(ans), ans[j] + 1, " ");

  return 0;
}

