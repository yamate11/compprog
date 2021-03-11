#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  ll cnt = 0;
  ll s = 0;
  for (int i = 0; i < N; i++) {
    ll a; cin >> a;
    if (a == 0) {
      cnt += s / 2;
      s = 0;
    }else {
      s += a;
    }
  }
  cnt += s / 2;
  cout << cnt << endl;

  return 0;
}

