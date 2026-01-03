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
  string s; cin >> s;
  

  auto f = [&](ll t0, ll t1) -> bool {
    vector<ll> A(N, 0LL);
    auto g = [&](ll prev, ll cur) -> bool { return (s[cur] == 'o') != (A[cur] == A[prev]); };
    A[0] = t0;
    A[1] = t1;
    REP(i, 1, N - 1) {
      A[i + 1] = g(i - 1, i);
    }
    bool b1 = A[0] == g(N - 2, N - 1);
    bool b2 = A[1] == g(N - 1, 0);
    if (b1 and b2) {
      REP(i, 0, N) cout << (A[i] == 0 ? 'S' : 'W');
      cout << "\n";
      return true;
    }else return false;
  };

  if (f(0, 0) or f(0, 1) or f(1, 0) or f(1, 1)) ;
  else cout << "-1\n";

  return 0;
}

