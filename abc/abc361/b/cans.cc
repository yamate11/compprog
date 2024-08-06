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

  // @InpVec(12, A) [lvSOFsFY]
  auto A = vector(12, ll());
  for (int i = 0; i < 12; i++) { ll v; cin >> v; A[i] = v; }
  // @End [lvSOFsFY]

  auto f = [&](ll a, ll b, ll c, ll d) {
    if (b <= c) return false;
    if (d <= a) return false;
    return true;
  };

  bool b1 = f(A[0], A[3], A[6], A[9]);
  bool b2 = f(A[1], A[4], A[7], A[10]);
  bool b3 = f(A[2], A[5], A[8], A[11]);
  cout << (b1 and b2 and b3 ? "Yes\n" : "No\n");
  

  return 0;
}

