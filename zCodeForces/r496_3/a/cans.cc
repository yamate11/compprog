#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
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

  ll n; cin >> n;
  vector<ll> A(n + 1);
  REP(i, n) cin >> A[i];
  A[n] = 0;
  ll cnt = 0;
  vector<ll> ans;
  REP(i, n) {
    if (A[i] >= A[i + 1]) {
      cnt++;
      ans.push_back(A[i]);
    }
  }
  cout << cnt << endl;
  for (ll a : ans) cout << a << " ";
  cout << endl;


  return 0;
}

