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
  // @InpVec(N, A) [fO2OLXwA]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [fO2OLXwA]
  A.resize(2*N);
  REP(i, 0, N) A[N + i] = A[i];
  ll i0 = 0;
  for (; i0 < N and A[i0] != 0; i0++);
  if (i0 == N) {
    cout << "-1\n";
    return 0;
  }
  vector<ll> Z0, Z2;
  Z0.push_back(i0);
  {
    ll i = i0 + 1;
    while (true) {
      for (; i < i0 + N and A[i] == 1; i++);
      if (i == i0 + N or A[i] == 0) {
        cout << "-1\n";
        return 0;
      }
      assert(i < i0 + N and A[i] == 2);
      Z2.push_back(i);
      i++;
      for (; i < i0 + N and A[i] == 1; i++);
      if (i == i0 + N) break;
      if (A[i] == 2) {
        cout << "-1\n";
        return 0;
      }
      assert(i < i0 + N and A[i] == 0);
      Z0.push_back(i);
      i++;
    }
  }
  ll k = ssize(Z0);
  assert(ssize(Z2) == k);
  vector<ll> ans(2*N, -1LL);
  REP(i, 0, k) {
    ans[Z0[i]] = i;
    ans[Z2[i]] = N - 1 - i;
  }
  ll seq = k;
  REP(i, 0, k) {
    REP(j, Z0[i] + 1, Z2[i]) ans[j] = seq++;
    ll t = i + 1 < k ? Z0[i + 1] : i0 + N;
    REPrev(j, t - 1, Z2[i] + 1) ans[j] = seq++;
  }
  REP(i, 0, N) if (ans[i] < 0) ans[i] = ans[i + N];
  REPOUT(i, 0, N, ans[i] + 1, " ");


  return 0;
}

