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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;
  auto f = [&](string C) -> ll {
    ll ret = 0;
    vector<ll> cnt(N + 1, 0LL);
    REPrev(i, N - 1, 0) cnt[i] = cnt[i + 1] + (S[i] == C[2] ? 1 : 0);
    REP(i, 0, N) if (S[i] == C[0]) REP(j, i + 1, N) if (S[j] == C[1]) {
        ret += cnt[j];
        if (ll idx = j - i + j; idx < N and S[idx] == C[2]) ret--;
      }
    return ret;
  };
  cout << f("RGB") + f("RBG") + f("GRB") + f("GBR") + f("BRG") + f("BGR") << endl;
  return 0;
}

