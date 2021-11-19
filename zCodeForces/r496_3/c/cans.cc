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

  multiset<ll> us;
  ll N; cin >> N;
  vector<ll> A(N);
  REP(i, N) {
    ll a; cin >> a;
    A[i] = a;
    us.insert(a);
  }
  ll cnt = 0;
  REP(i, N) {
    auto it = us.find(A[i]);
    us.erase(it);
    bool found = false;
    REP(j, 32) {
      ll x = 1LL << j;
      if (x <= A[i]) continue;
      if (us.find(x - A[i]) != us.end()) {
        found = true;
        break;
      }
    }
    if (not found) cnt++;
    us.insert(A[i]);
  }
  cout << cnt << endl;


  return 0;
}

