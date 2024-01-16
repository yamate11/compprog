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

  ll N; cin >> N;
  // @InpVec(N, A) [STlQubeI]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [STlQubeI]

  ll lim = 1e5;
  vector num(lim + 1, 0LL);
  REP(i, 0, N) num[A[i]]++;
  
  ll s = 0;
  REP(i, 0, N) s += A[i];

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll b, c; cin >> b >> c;
    s += (c - b) * num[b];
    num[c] += num[b];
    num[b] = 0;
    cout << s << "\n";
  }
  

  return 0;
}

