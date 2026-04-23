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

  string S; cin >> S;
  string T; cin >> T;
  ll N = ssize(S);
  ll M = ssize(T);
  vector<ll> pos(M, 0LL);
  ll tot = N * (N + 1) / 2;
  {
    ll p = 0;
    REP(i, 0, M) {
      while (p < N and S[p] != T[i]) p++;
      if (p == N) {
        cout << tot << endl;
        return 0;
      }
      pos[i] = p;
      p++;
    }
  }
  ll cnt = 0;
  REP(p, 0, N) {
    if (p <= pos[0]) cnt += N - pos[M - 1];
    else {
      auto func = [&]() -> bool {
        ll q = p;
        REP(i, 0, M) {
          while (q < N and S[q] != T[i]) q++;
          if (q == N) return false;
          pos[i] = q;
          if (i == M - 1 or pos[i] < pos[i + 1]) break;
          q++;
        }
        return true;
      };
      if (func()) {
        cnt += N - pos[M - 1];
      }else {
        break;
      }
    }
  }
  cout << tot - cnt << endl;

  return 0;
}

