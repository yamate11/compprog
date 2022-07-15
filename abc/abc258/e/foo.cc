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

  vector<ll> _area(10000);
  cout << "capacity = " << _area.capacity() << endl;
  _area.push_back(0);
  cout << "capacity = " << _area.capacity() << endl;
  auto vec = _area.begin() + 5000;
  cout << vec[-1] << endl; // OK
  
  _area.push_back(0);
  cout << vec[1] << endl; // NG

  return 0;
}

