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

  auto f = [&](string S, string T) {
    ll i = 0;
    while (i < ssize(S) and S[i] == T[i]) i++;
    ll j = ssize(S) - 1;
    while (j >= 0 and S[j] == T[j + 1]) j--;
    return j <= i;
  };

  ll K; cin >> K;
  string S, T; cin >> S >> T;
  ll ns = ssize(S);
  ll nt = ssize(T);

  bool ans = false;
  if (ns == nt) {
    ll cnt = 0;
    REP(i, 0, ns) if (S[i] != T[i]) cnt++;
    ans = cnt <= 1;
  }else if (nt == ns + 1) {
    ans = f(S, T);
  }else if (nt == ns - 1) {
    ans = f(T, S);
  }else {
    ans = false;
  }
  cout << (ans ? "Yes\n" : "No\n");

  return 0;
}

