#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(coordCompr)


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    CoordCompr cc;
    cc.add(0);
    cc.add(vector<ll>({10, -10}));
    assert(cc.c(0) == 1);
    assert(cc.c(10) == 2);
    assert(cc.c(-10) == 0);
  }
  {
    vector<ll> orig_values({0, -3000, 0, 9, 9, 10, 3, -1234567890123});
    vector<ll> save(orig_values);
    CoordCompr cc(orig_values);
    cc.add(1000);
    assert(cc.c(-3000) == 1);
    assert(cc.c(-1234567890123) == 0);
    assert(cc.c(9) == 4);
    assert(cc.c(1000) == 6);
    assert(cc.d(0) == -1234567890123);
    assert(cc.d(2) == 0);
    assert(cc.d(5) == 10);
    assert(cc.size() == 7);
    assert(orig_values == save);
    CoordCompr cc1(move(orig_values));
    cc1.add(1000);
    assert(cc1.c(-3000) == 1);
    for (ll x : save) assert(cc.c(x) == cc1.c(x));
  }
  {
    CoordCompr cc(vector<ll>{0,0,0,10});
    assert(cc.size() == 2);   // Immediately after construction
  }
  {
    CoordCompr<string> cc;
    cc.add("abc");
    cc.add("xyz");
    cc.add("lmn");
    cc.add("bbb");
    assert(cc.size() == 4);
    assert(cc.c("abc") == 0);
    assert(cc.c("xyz") == 3);
    assert(cc.d(1) == "bbb");
  }

  {
    using pll = pair<ll, ll>;
    CoordCompr<pll, map<pll, int>> cc;
    cc.add({5, 1});
    cc.add({2, 4});
    cc.add({3, 3});
    cc.add({3, 4});
    cc.add({2, 4});
    assert(cc.size() == 4);
    assert(cc.c({3, 3}) == 1);
    assert(cc.c({3, 4}) == 2);
    assert(cc.d(3) == pll(5, 1));
  }
  


  cout << "Test done." << endl;

}
  
