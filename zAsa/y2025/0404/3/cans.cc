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

  ll N, T; cin >> N >> T;
  // @InpMVec(T, ((A, dec=1), B)) [HRJ2eye3]
  auto A = vector(T, ll());
  auto B = vector(T, ll());
  for (int i = 0; i < T; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [HRJ2eye3]

  ll cur = 1;
  unordered_map<ll, ll> mp;
  mp[0] = N;
  vector<ll> vec(N, 0LL);
  REP(i, 0, T) {
    ll a = A[i];
    ll x = vec[a];
    ll y = x + B[i];
    if (--mp[x] == 0) cur--;
    if (mp[y]++ == 0) cur++;
    vec[a] = y;
    cout << cur << "\n";
  }

  return 0;
}

