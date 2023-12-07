#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(random)

int main() {
  {
    Random rand;
    vector<int> cnt(10);
    for (int i = 0; i < 10000; i++) {
      int c = rand.range(0, 10);
      cnt[c]++;
    }
    for (int i = 0; i < 10; i++) assert(900 <= cnt[i] and cnt[i] <= 1100);
  }
  {
    Random randA(3141);
    Random randB(3141);
    Random randC;
    ll cntAB = 0;
    ll cntAC = 0;
    for (int i = 0; i < 10000; i++) {
      ll a = randA.range(0, 10);
      ll b = randB.range(0, 10);
      ll c = randC.range(0, 10);
      if (a == b) cntAB++;
      if (a == c) cntAC++;
    }
    assert(cntAB == 10000 and 900 <= cntAC and cntAC <= 1100);
  }

  cerr << "ok\n";
}

