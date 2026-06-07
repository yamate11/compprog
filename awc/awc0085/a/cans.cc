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
  // @InpVec(N, S) [1wRGQiR6]
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; S[i] = v; }
  // @End [1wRGQiR6]
  vector<ll> ans(N);
  vector<ll> A(N);
  REP(i, 0, N) A[i] = i;
  ll r = 1;
  ll n = N;
  while (true) {
    if (n == 1) {
      ans[A[0]] = 0;
      break;
    }
    vector<ll> nxtA;
    REP(i, 0, n / 2) {
      ll win, lose;
      if (S[A[2 * i]] > S[A[2 * i + 1]]) {
        win = A[2 * i];
        lose = A[2 * i + 1];
      }else {
        win = A[2 * i + 1];
        lose = A[2 * i];
      }
      nxtA.push_back(win);
      ans[lose] = r;
    }
    A = move(nxtA);
    r++;
    n /= 2;
  }
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

