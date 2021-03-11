#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int popcount25(int x) {
  int ret = 0;
  for (int i = 0; i < 25; i++) {
    if ((x >> i) & 1) ret++;
  }
  return ret;
}

int popcount64(ll x) {
  int ret = 0;
  for (int i = 0; i < 64; i++) {
    if ((x >> i) & 1LL) ret++;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  stringstream ss1(argv[1]);
  ll type; ss1 >> type;
  stringstream ss2(argv[2]);
  ll N; ss2 >> N;

  ll cnt = 0;

  if (type == 1) {
    for (ll x = 0; x < (1LL << N); x++) {
      cnt += __builtin_popcountll(x);
    }
  }else if (type == 2) {
    for (ll x = 0; x < (1LL << N); x++) {
      cnt += __builtin_popcount((int)x);
    }
  }else if (type == 3) {
    for (ll x = 0; x < (1LL << N); x++) {
      cnt += popcount25((int)x);
    }
  }else if (type == 4) {
    for (ll x = 0; x < (1LL << N); x++) {
      cnt += popcount64((int)x);
    }
  }
  cout << cnt << endl;
}
