#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(int argc, char *argv[]) {
  stringstream ss1(argv[1]), ss2(argv[2]);
  ll N; ss1 >> N;
  ll type; ss2 >> type;

  if (type == 1) {
    ll res = 0;
    for (ll x = 0; x < (1LL << N); x++) {
      res |= x;
    }
    cout << res << endl;
  }

  if (type == 2) {
    bitset<1000> res2;
    for (ll x = 0; x < (1LL << N); x++) {
      bitset<1000> y(x);
      res2 |= y;
    }
    cout << res2.test(0) << endl;
  }

}
