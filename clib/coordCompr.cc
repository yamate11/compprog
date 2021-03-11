/*
  Coordinate Compression
  
  Usage:
    vector<ll> orig_values({0, -3000, 0, 9, 9, 10, 3, -1234567890123});
    CoordCompr cc(move(orig_values));
    cout << cc.c(-3000); //  ==> 1;   compress.
    cout << cc.d(2);     //  ==> 0;   decompress.
    cout << cc.size;     //  ==> 6;   the number of different values

  Tip:
    If you have x-y plane, do something like:

      CoordCompr cx(move(x_coords)), cy(move(y_coords));
      for (int i = 0; i < cx.size; i++) {
        for (int j = 0; j < cy.size; j++)  ... cx.d(i) ... cy.d(j) ....
          ... }}
 */


#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- coordCompr.cc

struct CoordCompr {
  int size;            // the number of different original values
  map<ll, int> mp;     // map from an original value to a compressed value
  vector<ll> rev;      // vector of original values

  CoordCompr(vector<ll> vec) {
    sort(vec.begin(), vec.end());
    for (int i = 0; i < (int)vec.size(); i++) {
      if (i == 0 || vec.at(i-1) != vec.at(i)) {
	mp[vec.at(i)] = rev.size();
	rev.push_back(vec.at(i));
      }
    }
    size = rev.size();
  }

  // compress
  int c(ll x) { return mp.at(x); }

  // decompress
  ll d(int i) { return rev.at(i); }
};

// @@ !! END ---- coordCompr.cc


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> orig_values({0, -3000, 0, 9, 9, 10, 3, -1234567890123});
  CoordCompr cc(move(orig_values));
  assert(cc.c(-3000) == 1);
  assert(cc.c(-1234567890123) == 0);
  assert(cc.c(9) == 4);
  assert(cc.d(0) == -1234567890123);
  assert(cc.d(2) == 0);
  assert(cc.d(5) == 10);
  assert(cc.size == 6);

  cout << "Test done." << endl;

}
  
