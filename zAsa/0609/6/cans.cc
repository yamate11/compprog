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
  // @InpVec(N, S, type=string) [BzeQKsr4]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [BzeQKsr4]

  vector<ll> numX(N);
  vector<ll> sumD(N);
  REP(i, 0, N) {
    for (char c : S[i]) {
      if (c == 'X') numX[i]++;
      else sumD[i] += c - '0';
    }
  }
  vector<ll> ord(N);
  REP(i, 0, N) ord[i] = i;
  sort(ALL(ord), [&](ll i, ll j) -> bool {
    return numX[j] * sumD[i] < numX[i] * sumD[j];
  });
  ll ans = 0;
  ll cumX = 0;
  REP(ii, 0, N) {
    ll i = ord[ii];
    for (char c : S[i]) {
      if (c == 'X') cumX++;
      else ans += (c - '0') * cumX;
    }
  }
  cout << ans << endl;

  return 0;
}

