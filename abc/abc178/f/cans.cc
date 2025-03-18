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
  // @InpVec(N, A, dec=0) [7ib2vEEd]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 0; A[i] = v; }
  // @End [7ib2vEEd]
  // @InpVec(N, B, dec=0) [7KfO4vLO]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 0; B[i] = v; }
  // @End [7KfO4vLO]

  vector AI(N, pll());
  vector BI(N, pll());
  REP(i, 0, N) AI[i] = pll(A[i], i);
  REP(i, 0, N) BI[i] = pll(B[i], i);
  reverse(ALL(BI));

  vector posA(N + 2, -1LL);
  vector posB(N + 2, -1LL);
  ll comm = -1;
  REP(i, 0, N) {
    ll a = AI[i].first;
    ll b = BI[i].first;
    if (posA[a] < 0) posA[a] = i;
    if (posB[b] < 0) posB[b] = i;
    if (a == b) comm = a;
  }
  posA[0] = posB[N + 1] = 0;
  posA[N + 1] = posB[0] = N;
  REPrev(i, N, 1) if (posA[i] < 0) posA[i] = posA[i + 1];
  REP(i, 1, N + 1) if (posB[i] < 0) posB[i] = posB[i - 1];
  bool possible = false;
  if (comm < 0) possible = true;
  else {
    ll lB = N - posB[comm - 1];
    ll q = max(posA[comm], posA[comm + 1] - lB);
    ll lA = posA[comm];
    ll r = min(posB[comm - 1], posB[comm] + lA);
    if (r < q) possible = false;
    else {
      possible = true;
      q = max(q, posB[comm]);
      ll lenA = posA[comm + 1] - q;
      vector<pll> tmpA;
      REP(i, 0, lenA) tmpA.push_back(AI[q + i]);
      REP(i, posA[comm + 1], N) AI[i - lenA] = AI[i];
      REP(i, 0, lenA) AI[N - lenA + i] = tmpA[i];
      ll lenB = q - posB[comm];
      vector<pll> tmpB;
      REP(i, 0, lenB) tmpB.push_back(BI[posB[comm] + i]);
      REPrev(i, posB[comm] - 1, 0) BI[lenB + i] = BI[i];
      REP(i, 0, lenB) BI[i] = tmpB[i];
    }
  }
  if (possible) {
    cout << "Yes\n";
    vector ans(N, 0LL);
    REP(i, 0, N) {
      auto [a, j] = AI[i];
      auto [b, k] = BI[i];
      ans[j] = b;
    }
    REPOUT(i, 0, N, ans[i], " ");
  }else {
    cout << "No\n";
  }


  return 0;
}

