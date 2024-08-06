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
  string S; cin >> S;

  ll r0 = 0, p0 = 0, s0 = 0;
  REP(i, 0, N) {
    ll r1 = r0, p1 = p0, s1 = s0;
    if (S[i] == 'R') {
      p0 = max(r1, s1) + 1;
      r0 = max(p1, s1);
      s0 = -1;
    }else if (S[i] == 'P') {
      s0 = max(p1, r1) + 1;
      p0 = max(s1, r1);
      r0 = -1;
    }else if (S[i] == 'S') {
      r0 = max(s1, p1) + 1;
      s0 = max(r1, p1);
      p0 = -1;
    }
  }
  cout << max(r0, max(s0, p0)) << endl;

  return 0;
}

