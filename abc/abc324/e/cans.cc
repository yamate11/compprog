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

  auto func = [&](const string& S, const string& T) -> ll {
    ll szs = SIZE(S);
    ll szt = SIZE(T);
    ll p = 0;
    REP(i, 0, szt) {
      for (; p < szs and S[p] != T[i]; p++);
      if (p == szs) return i;
      p++;
    }
    return szt;
  };

  ll N; cin >> N;
  string T; cin >> T;
  string TR = T;
  reverse(ALL(TR));
  ll szt = SIZE(T);
  auto pre = vector(N, 0LL);
  auto post = vector(N, 0LL);
  REP(n, 0, N) {
    string S; cin >> S;
    pre[n] = func(S, T);
    reverse(ALL(S));
    post[n] = func(S, TR);
  }
  sort(ALL(post));
  ll ans = 0;
  REP(n, 0, N) {
    ll s = lower_bound(ALL(post), szt - pre[n]) - post.begin();
    ans += N - s;
  }
  cout << ans << endl;
  return 0;
}

