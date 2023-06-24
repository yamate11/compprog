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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, S, type=char) [B40SnhdC]
  auto S = vector(N, char());
  for (int i = 0; i < N; i++) { char v; cin >> v; S[i] = v; }
  // @End [B40SnhdC]
  vector<ll> cnt(26, 0LL);
  REP(i, 0, N) cnt[S[i] - 'A'] = 1;
  if (accumulate(ALL(cnt), 0LL) == 3) {
    cout << "Three" << endl;
  }else {
    cout << "Four" << endl;
  }

  return 0;
}

