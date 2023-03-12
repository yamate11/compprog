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

  ll N, K; cin >> N >> K;
  string S; cin >> S;
  ll nX = 0;
  REP(i, 0, N) if (S[i] == 'X') nX++;
  if (nX == K) {
    cout << N - 1 << endl;
    return 0;
  }
  if (nX < K) {
    REP(i, 0, N) {
      if (S[i] == 'X') S[i] = 'Y';
      else S[i] = 'X';
    }
    nX = N - nX;
    K = N - K;
  }
  assert(nX > K);
  if (nX == N) {
    if (K == 0) {
      cout << 0 << endl;
    }else {
      cout << K - 1 << endl;
    }
    return 0;
  }
  // 1 <= nX <= K - 1
  ll posY = -1;
  vector<ll> cont;
  ll ans = 0;
  REP(i, 0, N) {
    if (S[i] == 'Y') {
      if (posY >= 0) {
        if (posY == i - 1) {
          ans++;
        }else {
          cont.push_back(i - posY - 1);
        }
      }
      posY = i;
    }
  }
  sort(ALL(cont));
  for (ll c : cont) {
    if (c <= K) {
      ans += c + 1;
      K -= c;
    }else {
      break;
    }
  }
  ans += K;
  cout << ans << endl;


  return 0;
}

