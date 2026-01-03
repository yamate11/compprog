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
  // @InpVec(N, L) [tJcF3vVe]
  auto L = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; L[i] = v; }
  // @End [tJcF3vVe]

  ll cnt = 0;
  REP(i, 0, N) REP(j, i + 1, N) REP(k, j + 1, N) {
    if (L[i] != L[j] and L[i] != L[k] and L[j] != L[k]
        and L[i] + L[j] > L[k]
        and L[j] + L[k] > L[i]
        and L[k] + L[i] > L[j]) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

