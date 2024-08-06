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
  string S; cin >> S;
  vector hand(N, 0LL);
  ll common = 0;
  REP(i, 0, M) {
    ll j = i % N;
    hand[j]++;
    if (S[i] == '0') {
    }else if (S[i] == '+') {
      hand[j] += common;
      common = 0;
    }else if (S[i] == '-') {
      common += hand[j];
      hand[j] = 0;
    }
  }
  REPOUT(i, 0, N, hand[i], "\n");
  

  return 0;
}

