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

  ll N, K; cin >> N >> K;
  string S; cin >> S;
  ll nx = 0, ny = 0;
  for (char c : S) {
    if (c == 'X') nx++;
    else ny++;
  }
  if (K > nx) {
    REP(i, 0, N) S[i] = S[i] == 'X' ? 'Y' : 'X';
    K = N - K;
  }
  vector cont(N + 1, 0LL);
  ll prev = -1;
  ll tb = 0;
  ll te = 0;
  ll ta = 0;
  REP(i, 0, N + 1) {
    if (i == N) {
      if (prev == -1) ta = N;
      else te = N - 1 - prev;
      break;
    }
    if (S[i] == 'Y') {
      if (prev == -1) tb = i;
      else cont[i - prev - 1]++;
      prev = i;
    }
  }
  ll ans = cont[0];
  ll idx = 1;
  ll k = K;
  while (k > 0) {
    for (; idx < N + 1 and cont[idx] == 0; idx++);
    if (idx == N + 1) break;
    if (k >= idx) {
      ans += idx + 1;
      k -= idx;
      cont[idx]--;
    }else {
      ans += k;
      k = 0;
      cont[idx]--;
      break;
    }
  }
  ans += min(k, tb);
  k -= min(k, tb);
  ans += min(k, te);
  k -= min(k, te);
  if (ta > 0) ans = max(0LL, k - 1);
  cout << ans << endl;

  return 0;
}

