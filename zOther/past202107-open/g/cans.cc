#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A;
  while (N > 0) {
    A.push_back(N % 3);
    N = N / 3;
  }
  A.push_back(0);
  vector<ll> B;
  ll sz = SIZE(A);
  ll pow = 1;
  ll carry = 0;
  REP(i, sz) {
    ll t = A[i] + carry;
    if (t == 3) {
      carry = 1;
    }else if (t == 2) {
      carry = 1;
      B.push_back(-pow);
    }else if (t == 1) {
      carry = 0;
      B.push_back(pow);
    }else if (t == 0) {
      carry = 0;
    }
    pow *= 3;
  }
  cout << SIZE(B) << endl;
  for (ll b : B) cout << b << " ";
  cout << endl;

  return 0;
}

